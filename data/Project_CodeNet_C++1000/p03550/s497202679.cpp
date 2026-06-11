#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n,z,w;cin>>n>>z>>w;
    if(n==1){
        ll a;cin>>a;
        ll res=abs(a-w);
        cout<<res<<endl;
        return 0;
    }
    n++;
    vector<ll> a(n);
    a[0]=z;
    rep(i,n-1) cin>>a[i+1];
    ll buf1=abs(a[n-1]-a[n-2]),buf2=abs(a[n-1]-w);
    ll res=max(buf1,buf2);
    cout<<res<<endl;
}
