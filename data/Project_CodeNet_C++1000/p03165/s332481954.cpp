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

    int main()
    {
            fast
          string s,t;
          cin>>s>>t;
          int dp[s.length()+1][t.length()+1];
          for(int i=0;  i<=s.length(); i++)
            dp[i][0]=0;
          for(int i=0;  i<=t.length(); i++)
            dp[0][i]=0;


            string ans="";
         for(int i=1;i <=s.length(); i++)
         {
             for(int j=1; j<=t.length(); j++)
             {
                 if(s[i-1]==t[j-1])
                    {
                        dp[i][j]=dp[i-1][j-1]+1;
                    }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
             }
         }

         int i=s.length(),j=t.length();
         while(i>0 && j>0)
         {
             if(s[i-1]==t[j-1])
              {
                  ans+=s[i-1];
                  i--;
                  j--;
              }
              else
              {
                  if(dp[i-1][j]>=dp[i][j-1])
                    i--;
                  else
                    j--;
              }
         }
         reverse(ans.begin(), ans.end());
         cout<<ans;


        return 0;

    }

