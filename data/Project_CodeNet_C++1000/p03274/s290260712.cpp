#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(ll)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n,k;cin>>n>>k;
    vector<ll>x(n);
    rep(i,n) cin>>x[i];
    ll res=1e+18;
    for(ll i=0;i+k<=n;i++){
        ll now1=abs(x[i])+abs(x[i]-x[k+i-1]);
        ll now2=abs(x[k+i-1])+abs(x[i]-x[k+i-1]);
        res=min(res,min(now1,now2));
    }
    cout<<res<<endl;
}
