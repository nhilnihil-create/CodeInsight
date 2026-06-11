#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N,D,X;
    cin>>N>>D>>X;
    vector<int> A(N);
    rep(n,0,N) cin>>A.at(n);

    uint64_t choco=X;
    for(auto a:A){
        uint64_t d=1;
        while(d<=D){
            choco++;
            d+=a;
        }
    }

    cout<<choco<<endl;
}