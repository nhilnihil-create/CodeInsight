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
    ll count=0;
    cin>>N>>K;
    if(K%2==0) {
        ll a=K/2;
        if(N%K>=a)
        count+=pow(N/K,3)+pow(N/K+1,3);
        else count+=2*pow(N/K,3);

    }
    else count+=pow(N/K,3);
    cout<<count<<endl;
    }