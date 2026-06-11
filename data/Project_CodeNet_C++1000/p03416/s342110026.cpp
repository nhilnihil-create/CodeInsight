#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define INF 1000000007
#define mod 1005
#define ll long long int
const double mx = 2e6 + 5 ;
bool check(int num)
{
	vector<int> digits;
	while(num)
	{
		digits.push_back(num%10);
		num/=10;
	}
	int len = digits.size();
	for(int i=0; i<len; i++)
	{
		if(digits[i]!=digits[len-i-1])
			return false;
	}
	return true;
}
void solve()
{
	int a, b;
	cin>>a>>b;
	int cnt = 0;
	for(int i=a; i<=b; i++)
	{
		if(check(i))
			cnt++;
	}
	cout<<cnt<<"\n";
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