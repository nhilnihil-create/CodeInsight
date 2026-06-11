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
    int dp[100005];
    bool dfs(int stones[], int k,int n)
    {
         //cout<<k<<" \n";
        if(k==0)
            return false;
       bool ans =false;
       if(dp[k]!=-1)
        return dp[k];
       for(int i=0; i<n; i++)
       {
           if(k-stones[i]>=0)
           {
                if(!dfs(stones, k-stones[i],n))
               {
                   ans = true;
                   break;
               }
           }

       }
      // cout<<k<<" "<<ans<<"\n";
       return dp[k]=ans;
    }
    int main()
    {
            fast
         int n,k;
         cin>>n>>k;
         int stones[n];
         for(int i=0; i<n; i++)
         {
             cin>>stones[i];
         }
         memset(dp,-1,sizeof(dp));
       if(dfs(stones, k,n))
        cout<<"First";
       else
        cout<<"Second";

        return 0;

    }

