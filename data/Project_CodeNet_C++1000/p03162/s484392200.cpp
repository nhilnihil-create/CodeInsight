#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define ll long long
#define fr(i,a,b) for (int i=a ; i<b ; i++)
#define fre(i,a,b) for (int i=a ; i<=b ; i++)
#define mem(a, b) memset(a, (b), sizeof(a))
#define mp make_pair
#define pb push_back
#define inf (int)1e9
#define pii 3.1415926535897932384626433832795
#define mod 1000000007
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pi> vii;
typedef map<int,int> mi;
typedef set<int> si;

const int N = 1e5+10;
 
int n;
int a[N][3];
int dp[N][3];

int solve (int day, int bef) {
	if (day == n)
		return 0;
	
	int &r = dp[day][bef];
	if (r != -1) return r;
	for (int i = 0; i < 3; i++)
		if (i != bef)
			r = max (r, solve (day+1, i) + a[day][i]);
		
	return r;
}
 
int main () {
	memset (dp, -1, sizeof dp);
	scanf ("%d", &n);
	for (int i = 0; i <n; i++)
		for (int j = 0; j < 3; j++)
			scanf ("%d", &a[i][j]);
		
	int ans = -1;
	for (int i = 0; i < 3; i++)
		ans = max (ans, solve (1, i) + a[0][i]);
	printf ("%d\n", ans);
 
	return 0;
}