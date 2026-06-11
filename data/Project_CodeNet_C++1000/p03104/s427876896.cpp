#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int64_t XORsum(int64_t n){
    int64_t v;
    if(n%2==0){
        v=(n%4>0);
        v+=n;
    }else{
        v=!((n-1)%4);
    }
    cerr<<v<<endl;
    return v;
}

int main(){
    int64_t A,B; cin>>A>>B;

    int64_t ans=XORsum(B);
    ans^=XORsum(max((int64_t)0,A-1));
    cout<<ans<<endl;
}