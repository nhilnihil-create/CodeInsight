#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int64_t Kaijo(int n){
    int64_t v=1;
    _rep(i,n,1) v*=i;
    return v;
}

int64_t Comb(int n, int m){
    return Kaijo(n)/Kaijo(m)/Kaijo(n-m);
}

int main(){
    int N,M; cin>>N>>M;

    int64_t t=100*(N-M)+1900*M;
    double p=pow(0.5,M);
    int64_t ans=t/p;

    cout<<ans<<endl;
}