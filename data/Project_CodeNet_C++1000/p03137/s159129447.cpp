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
int main() {
    ll N,K;
    cin>>K>>N;
    vec A(N),B(N);
    rep(i,0,N) {
        cin>>A[i];
    }
    sort(A);
    rep(i,0,N-1) {
        B[i]=A[i+1]-A[i];
    }
    sort(B);
    reverse(B);
    ll count=0;
  
    rep(i,0,min(K-1,N-1)) {
        count+=B[i];
        //cout<<B[i]<<endl;
    }
    ll a=A[N-1]-A[0];
    
    a-=count;
    cout<<a<<endl;
    }