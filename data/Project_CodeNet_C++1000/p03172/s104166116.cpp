// KOI NI YAAR SAB SAHI HOEGA  BAS  CHORRO MAT
// ENJOR KARO YAAR
// HAAR MAT MAANO
// // APNA TIME AAYEGA
// BEILIEVE IN GOD
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define loop(i,a,b) for(lli i=a;i<b;i++)
#define loopb(i,a,b) for (lli i=a;i>=b;i--)
#define pb push_back
#define mod 1000000007
#define fast() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) (__gcd((a),(b)))
#define lcm(a,b)(((a)*(b))/gcd((a),(b)))
#define ma 1e18
#define bc __builtin_popcountll
#define vi vector<lli>
#define pr pair<lli,lli>
#define vp vector<pr>
#define F  first
#define S   second
#define lld long double
#define PI  3.14159265358979
#define pri  priority_queue<ll>
#define prim  priority_queue<ll,vector<ll>,greater<ll>>
#define flush  cout<<flush


//lli vis[3000];
//vector<lli>v[3000];

/*void dfs(lli num)
{vis[num]=1;
for(auto itr = v[num].begin();itr!=v[num].end();++itr)
{if(vis[*itr]==0)
{dfs(*itr);
}
}
}*/

lli a[101];



int main()
{ lli n,k;
cin>>n>>k;
loop(i,0,n)
{cin>>a[i];
}
lli dp[n+1][k+1];
lli pf[n+1][k+1];
loop(i,0,k+1)
{if(i<=a[0])
{dp[0][i]=1;
}
else
{dp[0][i]=0;
}
}
loop(i,0,k+1)
{if(i==0)
{pf[0][i]=dp[0][i]%mod;
}
else
{pf[0][i]=(pf[0][i-1]%mod +dp[0][i] %mod)%mod;
}
}

loop(i,1,n)
{loop(j,0,k+1)
{if(j<=a[i])
{dp[i][j]=(pf[i-1][j] %mod);
}
else
{dp[i][j]=(pf[i-1][j] - pf[i-1][j-a[i]-1] + mod)%mod;
}
}
loop(j,0,k+1)
{if(j==0)
{pf[i][j]=dp[i][j]%mod;
}
else
{pf[i][j]=(pf[i][j-1]%mod + dp[i][j]%mod)%mod;
}
}
}
cout<<dp[n-1][k]%mod;
}