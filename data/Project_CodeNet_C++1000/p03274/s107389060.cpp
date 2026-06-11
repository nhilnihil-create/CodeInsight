#include <bits/stdc++.h>
using namespace std;

const int N=2e5+100;
const int mod=1e9+7;
typedef long long ll;

int l[N],r[N];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n,k;cin>>n>>k;
    int nl=0,nr=0;
    for(int i=1;i<=n;i++){
         int x;cin>>x;
         if(x<0) l[++nl]=-x;
         else   r[++nr]=x;
    }

    reverse(l+1,l+1+nl);


    int ans=1e9;
    for(int i=0;i<=nl;i++){
            if(k-i>nr ||  k-i<0) continue;
        ans=min(ans,l[i]+r[k-i]*2);
    }
    for(int i=0;i<=nr;i++){
         if(k-i>nl || k-i<0 ) continue;
        ans=min(ans,l[k-i]*2+r[i]);
    }

    cout<<ans<<endl;
     return 0;
}
