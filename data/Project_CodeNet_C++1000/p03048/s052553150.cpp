#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int R,G,B,N; cin>>R>>G>>B>>N;

    int64_t ans=0;
    rep(r,0,N/R+1){
        rep(g,0,(N-r*R)/G+1){
            if((N-r*R-g*G)%B==0) ans++;
        }
    }

    cout<<ans<<endl;
}