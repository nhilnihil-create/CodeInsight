#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5+100;
ll Left[MAXN];
ll MaxLeft[MAXN];
ll Right[MAXN];
ll MaxRight[MAXN];
ll x[MAXN],v[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    int N;
    ll C;
    cin>>N>>C;
    for(int i=1;i<=N;++i)   cin>>x[i]>>v[i];
    x[N+1]=C;
    for(int i=1;i<=N;++i)
    {
        MaxLeft[i]=Left[i]=Left[i-1]+v[i]-(x[i]-x[i-1]);
        MaxRight[i]=Right[i]=Right[i-1]+v[N-i+1]-(x[N-i+2]-x[N-i+1]);
    }
    for(int i=2;i<=N;++i)
    {
        MaxLeft[i]=max(MaxLeft[i-1],MaxLeft[i]);
        MaxRight[i]=max(MaxRight[i-1],MaxRight[i]);
    }
    ll ans=0;
    for(int i=1;i<=N;++i)
    {
        ans=max(ans,Left[i]);
        ans=max(ans,Right[i]);
        ans=max(ans,Left[i]-x[i]+MaxRight[N-i]);
        ans=max(ans,Right[i]-(C-x[N-i+1])+MaxLeft[N-i]);
    }
    cout<<ans<<endl;
    return 0;
}
