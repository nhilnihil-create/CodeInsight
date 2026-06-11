#include<bits/stdc++.h>
#define ll 	 long long
#define pb push_back
#define mp make_pair
using namespace std;


int main()
{

int n; cin>>n;

int a[n+9];

for(int i=0; i<n; i++) cin>>a[i];

vector<int> dp(n+9, INT_MAX);

dp[0]=0;

if(n==1)
{
	cout<<dp[0]<<endl;
	return 0;
}
dp[1]= abs(a[0]-a[1]);

if(n==2)
{
		cout<<dp[1]<<endl;
	return 0;
}

for(int i=2; i<n; i++)
{
	dp[i] = min(( abs(a[i-1]-a[i]) + dp[i-1]), ( abs(a[i-2]-a[i]) + dp[i-2]));
}

cout<<dp[n-1]<<endl;

     return 0;
 }