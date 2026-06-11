#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int64_t N,M; cin>>N>>M;

    int64_t ans=0;
    rep(i,1,M/N+1){
        if(M%i==0 && M/i>=N){
            ans=i;
            if(((M/i)%N)%(M/i/N)==0){
                ans=(M/i/N)*i;
                i=ans;
            }
        }
    }
    
    cout<<ans<<endl;
}