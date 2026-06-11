#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100005;

// BIT
int bit[MAXN * 2], N;

inline int lowbit(int x) { return x & -x; }

inline void add(int x)
{
	for (int i = x; i <= N; i += lowbit(i))
		bit[i] += 1;
}

inline int query(int x)
{
	int ret = 0;
	for (int i = x; i > 0; i ^= lowbit(i))
		ret += bit[i];
	return ret;	
}

int a[MAXN], b[MAXN];

vector<int> v;

ll pos;

int n;

bool check(int m)
{
	for (int i = 1; i <= n; i++)
		b[i] = (m <= a[i] ? 1 : 0);
	for (int i = 1; i <= N; i++)
		bit[i] = 0;
	ll cnt = 0; int cur = 0;
	add(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cur += (b[i] ? 1 : -1);
		cnt += query(n + 1 + cur);
		add(n + 1 + cur);
	}
//	cerr << "cnt: " << cnt << endl;
	cnt = (ll)n * (n + 1) / 2 - cnt;
	return cnt < pos;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], v.emplace_back(a[i]);
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	N = 2 * n + 1, pos = (ll)n * (n + 1) / 4 + 1;
	int l = 0, r = v.size() - 1;
	while (l < r)
	{
		int mid = (l + r + 1) >> 1;
		if (check(v[mid]))
			l = mid;
		else
			r = mid - 1;
	}
	cout << v[l] << endl;
	return 0;	
}
