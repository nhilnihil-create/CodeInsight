#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n,k;cin>>n>>k;
    vector<ll> a(n),d(100,0);
    rep(i,n) cin>>a[i];
    rep(i,n){
        rep(j,40)if(a[i]&((ll)1<<j))d[j]++;
    }
    ll l=0;
    for(int j=40;j>=0;j--){
        if(d[j]>(n/2))continue;
        if(l+((ll)1<<j)<=k) l+=((ll)1<<j);
    }
    ll res=0;
    rep(i,n){
        res+=a[i]^l;
    }
    cout<<res<<endl;
}
