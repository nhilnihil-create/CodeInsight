#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n,m;cin>>n>>m;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    a[0]%=m;
    rep(i,n-1){
        a[i+1]+=a[i];
        a[i+1]%=m;
    }
    map<ll,ll> mp;
    ll res=0;
    rep(i,n){
        res+=mp[a[i]];
        mp[a[i]]++;
        if(a[i]==0)res++;
    }
    cout<<res<<endl;
}