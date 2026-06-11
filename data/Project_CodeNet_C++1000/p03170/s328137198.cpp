#include <bits/stdc++.h>
#define ll         long long int 
#define pb         push_back
#define umap       unordered_map
#define mod        1000000007
#define all(x)     (x).begin(), (x).end()
#define MN(a,b,c)  min(a,min(b,c))
#define pr         pair<ll,ll>
#define F          first
#define S          second
#define mP         make_pair
#define f(i,n)     for(int i=0;i<n;i++)
#define f1(i,x,y)  for(int i=x;i<=y;i++)
#define f2(i,x,y)  for(int i=x;i>=y;i--)
//__builtin_popcount(x)
//__builtin_parity(x)   =(number of set bits)%2
//__builtin_clz(x)      to count the number of leading  zeroes 
//__builtin_ctz(x)      to count the number of trailing zeroes 
//__gcd(a,b)
using namespace std;
int main()
{
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 int n,k;cin>>n>>k;
 vector <int> dp(k+1,-1);
 vector <int> a(n);
 f(i,n){cin>>a[i];dp[a[i]]=1;}
 // dp[x]=1 means Taro would win when k==x
 for(int i=1;i<=k;i++)
 {
    if(dp[i]==-1)
    {dp[i]=0;
    f(j,n)
    {
      if(a[j]>i)break;
      else
      {
        if(dp[i-a[j]]==0)
          {dp[i]=1;break;}
      }
    }
    }
 }
 if(dp[k]==1)
   cout<<"First"<<"\n";
 else 
   cout<<"Second"<<"\n";
}