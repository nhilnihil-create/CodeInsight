#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int64_t K,A,B; cin>>K>>A>>B;

    uint64_t ans=K+1;
    if(B-A-2>0){
        int64_t t=(K-A+1)/2;
        if(t>0) ans=A+(B-A)*t+(K-A+1)%2;
    }

    cout<<ans<<endl;
}