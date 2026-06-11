    #include <bits/stdc++.h>
    using namespace  std;
    #define MAXNUM 222222
    #define rep(i,s,t) for(int i=s;i<t;i++)
    typedef long long ll;
    const ll mod=1e9+7;
    void add(ll &a,ll b)
    {
        a+=b;
        if(a>=mod)a-=mod;
    }
    int c[MAXNUM];ll bef[MAXNUM],dp[MAXNUM];
    int main()
    {
        int n;scanf("%d",&n);
        dp[0]=1;
        rep(i,1,n+1)
        {
            scanf("%d",&c[i]);
            dp[i]=dp[i-1];
            if(bef[c[i]]&&bef[c[i]]!=i-1)
                add(dp[i],dp[bef[c[i]]]);
            bef[c[i]]=i;
        }
        printf("%lld\n",dp[n]);
    }