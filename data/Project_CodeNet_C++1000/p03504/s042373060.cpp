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
    int n,c;cin >> n >> c;
    vector<P> C[32];
    for(int i=0;i<n;i++){
        int s,t,cc;cin >> s >> t >> cc;
        cc--;
        C[cc].push_back({s,t});
    }
    vector<int> sum(100050);
    for(int i=0;i<c;i++){
        sort(C[i].begin(),C[i].end());
    }
    for(int i=0;i<c;i++){
        int f=-1;
        int nn=C[i].size();
        for(int j=0;j<nn;j++){
            if(f==-1) f=C[i][j].first;
            if(j+1==nn||C[i][j].second<C[i][j+1].first){
                sum[C[i][j].second+1]--;
                sum[f]++;
                f=-1;
            }
        }
    }
    for(int i=1;i<100050;i++) sum[i]+=sum[i-1];
    int ans=0;
    for(int i=0;i<100050;i++) chmax(ans,sum[i]);
    cout << ans << endl;
    return 0;
}