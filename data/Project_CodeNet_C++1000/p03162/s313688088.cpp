#include <bits/stdc++.h>
#define ll long long
#define mp(a, b) make_pair(a, b)
#define newline cout << endl;
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) v.begin(),v.end()
using namespace std;

template <typename S, typename T> ostream& operator<<(ostream& out, pair<S, T> const& p)
{
	out << '(' << p.ff << ", " << p.ss << ')';
	return out;
}

template <typename T> ostream& operator<<(ostream& out, vector<T> const& v)
{
	int l = v.size();
	for (int i = 0; i < l - 1; i++)
		out << v[i] << ' ';
	if (l > 0)
		out << v[l - 1];
	return out;
}

template <typename T> void trace(const char* name, T&& arg1) {
	cout << name << " : " << arg1 << endl;
}

template <typename T, typename ... Args> void trace(const char* names, T&& arg1, Args&&... args)
{
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | ";
	trace(comma + 1, args ...);
}

/*Input*/
const ll rows = 1e5+10;
const ll cols = 3;
ll activity[rows][cols], dp[rows][cols];
ll n;
/*Input*/

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	clock_t tStart = clock();
	int test;
	test = 1;
	/* cin >> test; */
	while (test--) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> activity[i][0];
			cin >> activity[i][1];
			cin >> activity[i][2];
		}

		for(int i = 0; i < n; i++) {
            if(i == 0) {
                dp[i][0] = activity[i][0];
                dp[i][1] = activity[i][1];
                dp[i][2] = activity[i][2];
            } else {
                dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + activity[i][0];
                dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + activity[i][1];
                dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + activity[i][2];
            }
		}

        cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])) << "\n";


	}
#ifdef LOCAL_DEFINE
	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
#endif
	return 0;
}






