#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

ll gcd(ll x,ll y) {return y ? gcd(y,x%y) : x;}
ll lcm(ll x, ll y) {return x/gcd(x,y)*y;}


int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];

    vector<ll> gl(n);
    gl[0]=a[0];
    rep(i,n-1){
        gl[i+1]=gcd(gl[i],a[i+1]);
    }
    vector<ll> gr(n);
    gr[n-1]=a[n-1];
    for(int i=n-1;i>=1;i--){
        gr[i-1]=gcd(gr[i],a[i-1]);
    }
    ll ans=gr[1];
    for(int i=1;i<n-1;i++){
        ans=max(ans,gcd(gl[i-1],gr[i+1]));
        //cout<<ans<<endl;
    }
    ans=max(ans,gl[n-2]);

    cout<<ans<<endl;
}