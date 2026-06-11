#include <bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(long long i=a; i<b; i+=1)
#define repr(i,a,b) for(long long i=a; i<=b; i+=1)
#define vec vector<ll>
#define map map<string,int>
#define repa(p,A) for(auto p:A)
#define pb push_back
#define sort(a) sort(a.begin(),a.end())
#define reverse(a) reverse(a.begin(),a.end())
const double PI=acos(-1);
 
using namespace std;

int main( ) {
    ll N,K;
    cin>>N>>K;
    vec A(N);
    rep(i,0,N) {
        cin>>A[i];
    }
    ll a=100000000000000000;
    rep(i,0,N-K+1) {
        ll c=min(abs(A[i])+abs(A[i+K-1]-A[i]),abs(A[i+K-1])+abs(A[i+K-1]-A[i]));
        a=min(a,c);     
    }
    cout<<a<<endl;
    }