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

D getExpectation(D x) {
   return perform(x)/x;
}

int main()
{
    cin>>N;
    set<Int> s;
    
    bool found=false;
    Int pos=1;
    while(!found){
        s.insert(N);
        if(N&1) N=3*N+1;
        else N/=2;
        pos++;
        if(s.count(N)) break;
        
    }
    cout<<pos<<"\n";
    
}