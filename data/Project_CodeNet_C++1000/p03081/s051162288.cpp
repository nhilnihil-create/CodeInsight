#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair <char, char> pcc;

const int N = 2e5 + 10;
int n, q;
string s;
pcc ar[N];

bool checkl(int x) {
	int i = 0;
	while (x >= 0 && i < q) {
		if (s[x] == ar[i].first) {
			if (ar[i].second == 'R')
				x++;
			else
				x--;
		}
		i++;
	}
	return x < 0;
}

bool checkr(int x) {
	int i = 0;
	while (x < n && i < q) {
		if (x < 0)
			return 0;
			
		if (s[x] == ar[i].first) {
			if (ar[i].second == 'R')
				x++;
			else
				x--;
		}
		i++;
	}
	return x > n - 1;
}

int32_t main() {
	cin >> n >> q >> s;
	for (int i = 0; i < q; i++)
		cin >> ar[i].first >> ar[i].second;
	
	int st = -1, ed = n;
	while (ed - st > 1) {
		int mid = st + ed >> 1;
		if (checkl(mid))
			st = mid;
		else
			ed = mid;
	}
	int l = st;
//	cout << "l : " << l << endl;
	
	st = -1, ed = n;
	while (ed - st > 1) {
		int mid = st + ed >> 1;
		if (checkr(mid))
			ed = mid;
		else
			st = mid;
	}
	int r = ed;
//	cout << "r : " << r << endl;
	cout << max(0LL, r - l - 1);
}