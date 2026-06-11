#include <bits/stdc++.h>
#define pb push_back
#define Int long long
using namespace std;

const int MAXN=500005;
const long MOD=(long)(1e9+7);
vector<int> adj[MAXN];
vector<pair<int,int>> G[MAXN];

Int N,M,K;
Int B,C,H,W;
Int X,Y,Z;
vector<Int> A;

Int ceilS(Int x,Int y){
    return (x+y-1)/y;
}
using D=long double;

Int perform(Int x){
    return (x*(x+1))/2LL;
}

int main()
{
        cin>>N>>X;
        A.resize(N);
        for(auto &x:A) cin>>x;
        Int sum=accumulate(A.begin(),A.end(),0LL);
        
        Int least=1e13;
        for(auto x:A) least=min(least,x);
        
        X-=sum;
        if(X<0) X=0;
        Int rem=X/least;
        
        cout<<N+rem<<"\n";
}