#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
const ll mod=1e+9+7;
int main(void){
    int n;string s;cin>>n>>s;
    map<char,int> mp;
    rep(i,n) mp[s[i]]++;
    ll res=1;
    for(auto& p:mp){
        res*=(p.second+1);
        res%=mod;
    }
    cout<<res-1<<endl;
}