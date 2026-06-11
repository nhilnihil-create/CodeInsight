#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int64_t N,A,B,C,D,E; cin>>N>>A>>B>>C>>D>>E;

    int64_t minT=min(A,min(B,min(C,min(D,E))));
    int64_t ans=N/minT+(N%minT>0);
    cout<<ans+4<<endl;
}