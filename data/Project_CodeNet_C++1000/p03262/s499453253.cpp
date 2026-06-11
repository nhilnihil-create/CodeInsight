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
ll gcd(ll a,ll b) {
    if(a%b==0) return b;
    return gcd(b,a%b);    
}

int main() {
    ll N,X;
    cin>>N>>X;
    vec A(N+1);
    rep(i,0,N) {
        cin>>A[i];
    }
    A[N]=X;
    sort(A);
    
    ll C=A[1]-A[0];
    
    rep(i,1,N) {
        ll D=A[i+1]-A[i];
        //cout<<D<<endl;
        C=gcd(C,D);
        }
        cout<<C<<endl;
        }