#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define mt make_tuple
#define MOD 1000000007
#define fo(i,a,b) for(i=a;i<b;i++)
#define foe(i,a,b) for(i=a;i<=b;i++)
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vl vector <long long int>
#define pii pair <int,int>
#define pll pair <long long int, long long int>
#define vpii vector< pair<int,int> >
#define vpll vector < pair <long long int,long long int> >
#define boost ios::sync_with_stdio(false); cin.tie(0)
using namespace std;
const int inf = 1e9 + 5;
const ll inf64 = 1e18 + 5;

int add(int x, int y) {return (x + y >= MOD ? x + y - MOD : x + y);}
int sub(int x, int y) {return (x < y ? x - y + MOD : x - y);}

int main()
{
	boost;
	int n, k, x, i;
	cin >> n >> k;
	int dp[k + 2], val[k + 1];
	memset(val, 0, sizeof val);
	
	val[0] = 1;
	fo(i, 0, n) {
		memset(dp, 0, sizeof dp);
		cin >> x;
		for(int j = 0; j <= k; j++) {
			int y = min(k, j + x);
			dp[j] = add(dp[j], val[j]);
			dp[y + 1] = sub(dp[y + 1], val[j]);
		}
		val[0] = dp[0];
		for(int j = 1; j <= k; j++)
		val[j] = add(dp[j], val[j - 1]);
	}
	cout << val[k];
}
