#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}

int main(){
    int n;cin >> n;
    vector<P> R(n),B(n);
    for(int i=0;i<n;i++) cin >> R[i].first >> R[i].second;
    for(int i=0;i<n;i++) cin >> B[i].first >> B[i].second;
    sort(R.begin(),R.end());
    sort(B.begin(),B.end());
    vector<int> ng;
    int ans=0;
    for(int i=0;i<n;i++){
        vector<P> list;
        for(int j=0;j<n;j++){
            if(B[i].first>R[j].first&&B[i].second>R[j].second){
                list.push_back(P(R[j].second,j));
            }
        }
        sort(list.rbegin(),list.rend());
        for(auto num: list){
            //cout << "要素" << num.first << " " << num.second << endl;
            bool ok=true;
            for(int j=0;j<ng.size();j++){
                if(ng[j]==num.second) ok=false;
            }
            if(!ok) continue;
            ng.push_back(num.second);
            ans++;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}