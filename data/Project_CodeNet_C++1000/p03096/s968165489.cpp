#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int maxn = 2e5+20, maxm=2e5+20;  
int  c[maxn], a[maxn];
ll mod=1e9 + 7;
const ll inf=1e9;
queue <int> q;
set <int> s;
set <int> s1;
int dp[maxn];

int X[]={119, 18, 93, 91, 58, 107, 111, 82, 127, 123};
 
int main()
{		 
	
	ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	
	for(int i=1;i<=n;i++)
		cin >> a[i];
	
	dp[0]=1;
	a[0]=a[1];	
	for(int i=1;i<=n;i++)	
	{
		if(a[i] == a[i-1])
			dp[i]=dp[i-1], c[a[i]]=i;
		else
			if(c[a[i]] != 0)
				dp[i]=(dp[c[a[i]]]+dp[i-1])%mod, c[a[i]]=i;		
			else
				dp[i]=dp[i-1]%mod, c[a[i]]=i;
	}
		
	cout << dp[n];
}
	
 
	

	
	
	
