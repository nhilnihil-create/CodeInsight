#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    ll ans=0,n;
    cin>>n;
    vec A(n),B(n);
    rep(i,n) cin>>A[i];
    rep(i,n) cin>>B[i];
    rep(i,29){
        ll z=0;
        vec C,D;
        ll a=pow(2,i);
        rep(j,n) C.push_back(A[j]%(2*a));
        rep(j,n) D.push_back(B[j]%(2*a));
        sort(all(D));
        rep(j,n){
            z+=upper_bound(all(D),2*a-1-C[j])-lower_bound(all(D),a-C[j]);
            z+=upper_bound(all(D),4*a-2-C[j])-lower_bound(all(D),3*a-C[j]);
        }
        if(z%2) ans+=a;
    }
    cout<<ans<<"\n";
}