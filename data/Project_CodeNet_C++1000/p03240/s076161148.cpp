#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define per1(i,n) for(int i=n;i>0;i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,x[101],y[101],h[101];
    cin>>n;
    rep(i,n) cin>>x[i]>>y[i]>>h[i];
    rep(i,101)rep(j,101){
        ll z=1,H,a;
        rep(k,n){
            if(h[k]!=0) H=h[k]+abs(i-x[k])+abs(j-y[k]),a=k;
        }
        rep(k,n){
            if(h[k]==0){
                if(abs(i-x[k])+abs(j-y[k])<H) z=0;
            }
            else if(h[k]+abs(i-x[k])+abs(j-y[k])!=H) z=0;
        }
        if(z){
            cout<<i<<" "<<j<<" "<<h[a]+abs(i-x[a])+abs(j-y[a]);
            return 0;
        }
    }
}