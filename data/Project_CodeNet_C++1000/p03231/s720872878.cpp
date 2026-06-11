#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define REP(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
using ll = long long;
signed main(){
    ll N,M;
    string S,T;
    cin>>N>>M>>S>>T;
    ll K=__gcd(N,M);
    for(ll i=0;i<K;i++)
        if(S[N/K*i]!=T[M/K*i]){
            puts("-1");
            return 0;
        }
    cout<<N/K*M<<endl;
}