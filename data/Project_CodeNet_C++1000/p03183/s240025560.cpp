#include <bits/stdc++.h>

using namespace std;

template<class T, class U>
void ckmin(T &a, U b)
{
	if (a > b) a = b;
}
template<class T, class U>
void ckmax(T &a, U b)
{
	if (a < b) a = b;
}

#define MP make_pair
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORD(i, a, b) for (auto i = (a) - 1; i >= (b); i--)
#define SZ(x) ((int) ((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define INF 1000000007
#define LLINF 2696969696969696969ll
#define MAXN 10013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N;
array<int, 3> arr[MAXN];
ll dp[MAXN];
ll ans;

bool cmp(array<int, 3> a, array<int, 3> b)
{
	return a[0] + a[1] < b[0] + b[1];
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	FOR(i, 0, N)
	{
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	//weight, solidness, value
	//when do you want to swap two guys? x + weight[i] > solid[j] => weight[i] - solid[j] > x x + weight[j] < solid[i], weight[i
	sort(arr, arr + N, cmp);
	//dp[weight] maximum value you can get!
	FOR(i, 0, N)
	{
		// cerr << arr[i][0] << endl;
		FORD(j, arr[i][1] + 1, 0)
		{
			ckmax(ans, dp[j] + arr[i][2]);
			if (j + arr[i][0] >= MAXN) continue;
			ckmax(dp[j + arr[i][0]], dp[j] + arr[i][2]);
		}
		// FOR(j, 0, 10)
		// {
		// 	cerr << dp[j] << ' ';
		// }
		// cerr << endl;
	}
	cout << ans << '\n';
	return 0;
}
