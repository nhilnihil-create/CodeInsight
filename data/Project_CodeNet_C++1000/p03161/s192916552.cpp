/*#include <iostream>
#include <bits/stdc++.h>
#define fast_cin ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define mp make_pair
#define ll long long int
using namespace std;

vector<ll> dp(100005,0);
int m=1e9+7;
bool cmp(pair<int,int>&a,pair<int,int>&b)
{
    if(a.second==b.second)
        return a.first<b.first;
    else
        return a.second<b.second;
}

bool cmp_(pair<int,pair<int,int> >&a,pair<int,pair<int,int> >&b)
{
   return a.second.first<b.second.first;
}

void factorial()
{
    dp[1]=1;
    for(int i=2;i<=100000;i++)
    {
        dp[i]=((dp[i-1]%m)*(i%m))%m;
    }
}

int main()
{
    fast_cin;
      string s,t;
      cin>>s>>t;
      int n=s.length();
      int m=t.length();
      unsigned int dp[n+1][m+1];
      string ans;
      for(int i=0;i<=n;i++)
      {
          for(int j=0;j<=m;j++)
          {
              if(i==0||j==0)
                dp[i][j]=0;
              else if(s[i-1]==t[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
              else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
              if(ans.length()<dp[i][j])
                ans+=s[i];
          }
      }
      cout<<dp[n][m]<<endl;
      //cout<<ans<<endl;
    return 0;
}*/
#include <iostream>
#include <bits/stdc++.h>
#define fast_cin ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define mp make_pair
#define ll long long int
using namespace std;

vector<ll> dp(100005,0);
int m=1e9+7;
bool cmp(pair<int,int>&a,pair<int,int>&b)
{
    if(a.second==b.second)
        return a.first<b.first;
    else
        return a.second<b.second;
}

bool cmp_(pair<int,int>&a,pair<int,int>&b)
{
   return a.second>b.second;
}

void factorial()
{
    dp[1]=1;
    for(int i=2;i<=100000;i++)
    {
        dp[i]=((dp[i-1]%m)*(i%m))%m;
    }
}
void binary(int n)
{
    // array to store binary number
    int binaryNum[32];

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}
int main()
{
    fast_cin;
    int t;
    t=1;
    while(t--)
    {
       int n,k;
       cin>>n>>k;
       int dp[n]={0};
       vector<int> v;
       for(int i=0;i<n;i++)
       {
           int u;
           cin>>u;
           v.pb(u);
       }
       for(int i=1;i<n;i++)
       {
           dp[i]=dp[i-1]+abs(v[i]-v[i-1]);
           for(int j=2;j<=k&&i>=j;j++)
           {
               dp[i]=min(dp[i],dp[i-j]+abs(v[i]-v[i-j]));
           }
       }
       cout<<dp[n-1];
    }
    return 0;
}
