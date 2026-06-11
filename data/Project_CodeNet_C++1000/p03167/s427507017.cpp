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
    int t;
    t=1;
    //int tc=0;
    while(t--)
    {
      int x,y;
      cin>>x>>y;
      vector<string> v;
      vector<vector<ll> > dp(x);
      int m=1e9+7;
      for(int i=0;i<x;i++)
      {
          dp[i].assign(y,0);
      }
      for(int i=0;i<x;i++)
      {
          string s;
          cin>>s;
          v.pb(s);
      }
      for(int j=1;j<y;j++)
      {
          if(v[0][j]=='#')
            break;
          dp[0][j]=1;
      }
      for(int i=1;i<x;i++)
      {
          if(v[i][0]=='#')
            break;
          dp[i][0]=1;
      }
      if(v[0][0]=='#')
        cout<<0;
      else
      {
           for(int i=1;i<x;i++)
          {
              for(int j=1;j<y;j++)
              {
                  if(v[i][j]=='#')
                    continue;
                  dp[i][j]=(dp[i-1][j]+dp[i][j-1])%m;
              }
          }
          cout<<dp[x-1][y-1];
      }
    }
    return 0;
}
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
    cin>>t;
    int tc=0;
    ll x=10000009;
    while(t--)
    {
       ll p,f,cnts,cntw,s,w;
       cin>>p>>f>>cnts>>cntw>>s>>w;
       ll ans=0;
       ll x1,y1,x2,y2;
       if(s>w)
       {
           swap(s,w);
           swap(cnts,cntw);
       }
       for(ll i=0;i<=cnts;i++)
       {
           x1=min(i,p/s);
           y1=min((p-(x1*s))/w,cntw);
           x2=min((cnts-x1),(f/s));
           y2=min((f-(x2*s))/w,cntw-y1);
           ans=max(ans,x1+y1+x2+y2);
       }
       cout<<ans<<endl;
    }
    return 0;
}*/
