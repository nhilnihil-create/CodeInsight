#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using Pair = pair<int, int>;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define INF 1000000007
#define SEP " "

int     main()
{
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = s[i] - '0';
	}
	int c = 0;
	if (a[0] == 0)
		c = 1;
	int max = 0;
	int r = 0;
	for (int l = 0; l < n; l++) {
		while(r < n && c <= k)
		{
			if (r+1 < n && a[r] == 1 && a[r+1] == 0)
				c++;
			r++;
		}
		if (r - l > max)
			max = r - l;
		if (l+1 < n && a[l] == 0 && a[l+1] == 1)
			c--;
	}
	cout << max << endl;
}

