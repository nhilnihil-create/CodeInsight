
// KOI NI YAAR SAB SAHI HOEGA  BAS  CHORRO MAT
// ENJOR KARO YAAR
// HAAR MAT MAANO
// // APNA TIME AAYEGA
// BEILIEVE IN GOD
#include<bits/stdc++.h>
using namespace std;
#define lli int
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
#define lld  double
#define PI  3.14159265358979
#define pri  priority_queue<ll>
#define prim  priority_queue<ll,vector<ll>,greater<ll>>
#define flush  cout<<flush

const lli  N=3e3+10;
 
vector<vector<lld>> dp(N,vector<lld>(N,-1)); 
lli n;
lld a[3000];



lld solve(lli index , lli tails)
{if(index == n)
{if(tails<=n/2)
{return 1;
}
else
{return 0;
}
}
if(dp[index][tails]!=-1)
{return dp[index][tails];
}
return dp[index][tails] = (a[index] *1.0 * solve(index+1,tails)) + (1-a[index])  * 1.0 * solve(index+1,tails+1);
}

int main()
{lli num;
fast();
cin>>n;

loop(i,0,n)
{cin>>a[i];
}

cout<<fixed<<setprecision(10)<<solve(0,0)<<"\n";
}
