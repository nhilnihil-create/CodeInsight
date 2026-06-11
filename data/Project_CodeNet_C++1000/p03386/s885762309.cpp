#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int A,B,K; cin>>A>>B>>K;

    rep(i,A,B+1){
        if(i<=A+K-1 || i>=B-K+1) cout<<i<<endl;
    }
}