#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define INF 1000000007
#define mod 1005
#define ll long long int
const double mx = 2e6 + 5 ;
bool isSame(int n)
{
	int x =  n%10;
	while(n)
	{
		if((n%10)!=x)
			return false;
		n/=10;
	}
	return true;
}
void solve()
{
	int n;
	cin>>n;
	int i = n;
	while(i)
	{
		if(isSame(i))
		{
			cout<<i<<"\n";
			break;
		}
		i++;	
	}	
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