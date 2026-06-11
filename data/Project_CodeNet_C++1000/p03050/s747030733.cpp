#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int64_t N; cin>>N;

    int64_t ans=0;
    for(int64_t k=1; k*k<=N; k++){
        if(N%k==0){
            if(N/k-1>k) ans+=N/k-1;
        }
    }

    cout<<ans<<endl;
}