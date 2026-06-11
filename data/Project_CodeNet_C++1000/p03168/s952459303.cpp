    #include<bits/stdc++.h>
    #include<math.h>

    typedef long long int ll;
    #define pb         push_back
    #define mp         make_pair
    #define F          first
    #define S          second
    #define fl(i,a,b)  for(ll i=a;i<b;i++)
    #define pll        pair<ll,ll>
    #define pii        pair<int,int>
    #define all(v)     v.begin(),v.end()
    #define M 1000000007
    #define tr(v, it) for(auto it = v.begin(); it != v.end(); it++)
    #define fast   ios::sync_with_stdio(false);cin.tie(0);cout.precision(10);cout << fixed;
    using namespace std;
    double dp[3005][3005];
    double dfs(int n, int i, double prob[], int cnt)
    {

        if(i>= n)
        {
            if(cnt> n/2)
                return 1;
            return 0;
        }
        if(dp[i][cnt]>-0.9)
            return dp[i][cnt];
        double ans=0;
        ans = ans + (prob[i]*dfs(n,i+1, prob, cnt+1));
        ans= ans + ((1-prob[i])*dfs(n,i+1,prob, cnt));
      //  cout<<i<<" "<<cnt<<" "<<ans<<"\n";
        return dp[i][cnt] =ans;
    }
    int main()
    {
            fast
         int n;
         cin>>n;
         double prob[n];
         for(int i=0; i<n; i++)
         {
             cin>>prob[i];
         }
         memset(dp,-1,sizeof(dp));
         printf("%0.10f",dfs(n,0,prob,0));

        return 0;

    }

