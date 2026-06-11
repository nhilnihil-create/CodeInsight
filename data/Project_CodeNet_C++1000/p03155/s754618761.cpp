/**
 * File              : A - Bulletin Board.cpp
 * Author            : horcrux2301 <khajuriaharsh729@gmail.com>
 * Date              : 12/02/2019 21:39:49
 * Last Modified Date: 12/02/2019 21:39:49
 */
#include <bits/stdc++.h>
#define ll long long
#define mp(a, b) make_pair(a, b)
#define newline cout << endl;
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>

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

template <typename T> void trace(const char* name, T&& arg1) { cout << name << " : " << arg1 << endl; }

template <typename T, typename... Args> void trace(const char* names, T&& arg1, Args&&... args)
{
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | ";
	trace(comma + 1, args...);
}

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	clock_t tStart = clock();
	int test;
	test = 1;
	// cin >> test;
	while (test--) {
		ll N,H,W;
		cin >> N >> H >> W;
		ll ans = 0;
		ans += (N-H+1)*(N-W+1);
		cout << ans << endl;
	}
#ifdef LOCAL_DEFINE
	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
#endif
	return 0;
}
