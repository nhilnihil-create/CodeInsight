#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N,M; cin>>N>>M;

    bitset<30> b(0);
    rep(n,0,N){
        bitset<30> _b(0);
        int K; cin>>K;
        rep(k,0,K){
            int a; cin>>a;
            _b.set(a-1);
        }

        if(n==0) b|=_b;
        else b&=_b;
    }

    cout<<b.count()<<endl;
}