#include<bits/stdc++.h>
using namespace std;

const int maxn = (5e5 + 12);
long long fen[maxn], a[maxn], b[maxn], n, m, low, high, mid;
vector <int> v;

void add(long long idx) {
	for ( ; idx < maxn; idx += (idx & -idx))
		fen[idx]++;
}

long long get(long long idx) {
	long long ret = 0;
	for (; idx; idx -= (idx & -idx))
		ret += fen[idx];
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		v.push_back(a[i]);
	}
	
	sort(v.begin(), v.end());
	v.resize(distance(v.begin(), unique(v.begin(), v.end())));
	m = v.size();
	
	high = m;
	while(high - low > 1) {
		mid = (high + low) >> 1;
		long long now = 0ll;
//		cout << v[mid] << '\n';
		for (int i = 0; i < n; i++) {
			if(v[mid] > a[i]) b[i] = 1ll;
			else b[i] = -1ll;
		}
		for (int i = 0; i < maxn; i++)
			fen[i] = 0;
		b[0] += n + 2;
//		cout << b[0] << ' ';
		add(n + 2);
		now = get(b[0] - 1);
		add(b[0]);
		for (int i = 1; i < n; i++) {
			b[i] += b[i - 1];
//			cout << b[i] << ' ';
			now += get(b[i] - 1);
			add(b[i]);
		}
		if (now > ((n * (n + 1) / 2) / 2))
		   high = mid;
		else
			low = mid;
//		cout << v[mid] << ' ' << now << '\n';
//		cout << '\n';
	}
	cout << v[low];
	return 0;
}
