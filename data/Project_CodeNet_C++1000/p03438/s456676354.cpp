#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<float.h>
#include<tuple>
#include<string.h>
#include<iomanip>
#include<stack>
#include<queue>
#include<map>
#include<deque>

using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define ALLOF(c) (c).begin(), (c).end()
#define Pa pair<ll,ll>
const ll mod=1000000007;
const ll INF=10e12;
const ll inf=-1;
ll ABS(ll a){return max(a,-a);}


int main(void){
    ll N,kaisu=0;
    cin>>N;
    vector<ll> A(N),B(N);
    rep(i,N) cin>>A.at(i);
    rep(i,N) cin>>B.at(i);
    rep(i,N) kaisu+=B.at(i)-A.at(i);
        
    ll needa=0,needb=0;
    rep(i,N){
        if(A.at(i)>B.at(i)) needb+=A.at(i)-B.at(i);
        else if(A.at(i)<B.at(i)) needa+=(B.at(i)-A.at(i)+1)/2;
    }
    if(needa<=kaisu && needb<=kaisu) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
