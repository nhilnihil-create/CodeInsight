#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    ll n,z,w,A[200001];
    cin>>n>>z>>w;
    rep(i,n) cin>>A[i];
    cout<<max(abs(w-A[n-1]),abs(A[n-2]-A[n-1])*(n!=1))<<"\n";
}
