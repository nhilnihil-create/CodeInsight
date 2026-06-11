#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define INF 1000000007
#define mod 1005
#define ll long long int
const double mx = 2e6 + 5 ;

/*
0123
n = 4
i<2

*/
void solve()
{
	string s;
	cin>>s;
	int fav = 753;
	int minPos = INT_MAX;
	int n = s.length();
	for(int i=0; i<n-2; i++)
	{
		int ones = s[i+2]-'0';
		int tens = s[i+1]-'0';
		int hundreds = s[i]-'0';
		int num = ones + tens*10 + hundreds*100;
		minPos = min(minPos, abs(num-fav));
	}
	cout<<minPos<<"\n";
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