#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int64_t a,b,c,k,ans; cin>>a>>b>>c>>k;
    if(k%2) ans=b-a;
    else ans=a-b;
    cout<<ans<<endl;
}