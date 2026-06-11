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
    cin>>N>>K;
    A.resize(N);
    
    for(auto &x:A) cin>>x;
    sort(A.begin(),A.end());
    multiset<Int> m;
    Int best=1e13;
    for(int i=0;i<K;++i){
        m.insert(A[i]);
    }
    best=min(best,*m.rbegin()-*m.begin());
    for(int i=K;i<N;++i){
        m.insert(A[i]);
        m.erase(m.find(A[i-K]));
        best=min(best,*m.rbegin()-*m.begin());
    }
    cout<<best<<"\n";
    
}