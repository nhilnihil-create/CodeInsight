#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define INF 1000000007
#define mod 1005
#define ll long long int
const double mx = 2e6 + 5 ;

int findSum(int num)
{
	int dS = 0;
	while(num)
	{
		dS+=(num%10);
		num/=10;
	}
	return dS;
}
void solve()
{
	int n, a, b;
	cin>>n>>a>>b;
	int sum = 0;
	for(int i=1; i<=n; i++)
	{
		if(findSum(i)>=a && findSum(i)<=b)
		{
			sum+=i;
		}
	}	
	cout<<sum<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}