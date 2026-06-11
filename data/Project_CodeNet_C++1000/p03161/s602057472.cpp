#include <bits/stdc++.h>
#define rep(n) for (int i=0;i<n;i++)
#define ll long long 
using namespace std;
int T;
void solve()
{int k,n; scanf("%d%d",&n,&k); vector<int> h(n);
vector<int> dp(n,1e9+5);dp[0]=0;
for(int& x:h)
	scanf("%d",&x);
for(int i=0;i<n;i++)
{for(int j=i+1;j<=k+i;j++){
if(j<n)dp[j]=min(dp[j],dp[i]+abs(h[i]-h[j]));}
}
printf("%d\n",dp[n-1]);	
}

int main ()
{
T=1;
//cin >> T;
while(T-->0)
{solve();	
}
}

