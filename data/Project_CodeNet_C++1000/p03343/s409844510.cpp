#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    ll n,k,q,A[200001],ans=1e18;
    cin>>n>>k>>q;
    rep(i,n) cin>>A[i];
    rep(i,n){
        vec B,C;
        ll a=0;
        rep(j,n){
            if(A[j]>=A[i]) B.push_back(A[j]);
            if(A[j]<A[i]||j==n-1){
                sort(all(B));
                rep(l,max(0,int(B.size()-k+1))) C.push_back(B[l]);
                B.clear();
            }
        }
        sort(all(C));
        if(C.size()>=q){
            rep(j,q) a=max(a,C[j]);
            ans=min(ans,a-A[i]);
        }
    }
    cout<<ans;
}