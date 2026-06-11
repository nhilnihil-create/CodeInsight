#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
int main(){
    string s;cin >> s;
    int k;cin >> k;
    vector<string> v;
    for(int i=1;i<=5;i++){
        for(int j=0;j<s.size();j++){
            string t;
            for(int k=0;k<i;k++){
                if(j+k>=s.size()) continue;
                t+=s[j+k];
            }
            v.push_back(t);
        }
    }
    sort(v.begin(),v.end());
    int cnt=0;
    string pre="";
    for(int i=0;i<v.size();i++){
        if(pre!=v[i]){
            cnt++;
            pre=v[i];
        }
        if(cnt==k){
            cout << pre << endl;
            return 0;
        }
        //cout << pre << " " << cnt << endl;
    }
    return 0;
}