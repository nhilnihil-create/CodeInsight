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

// vector<vector<lli>> pre(3001,vector<lli>(3001,0)); 
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

lli a[100009];
lli dp[100009];
lli n,k;

lli solve(lli stones)
{if(stones<a[0])
{return 0;
}
if(dp[stones]!=-1)
{return dp[stones];
}
lli ans=0;
loop(i,0,n)
{if(stones>=a[i])
{ans|=(solve(stones-a[i])==0);}}
return dp[stones]=ans;
}

int main()
{lli t;
cin>>n>>k;
loop(i,0,n)
{cin>>a[i];
}
lli res;
mem(dp,-1);
res = solve(k);
if(res==0)
{cout<<"Second"<<"\n";
}
else
{cout<<"First"<<"\n";
}
}
