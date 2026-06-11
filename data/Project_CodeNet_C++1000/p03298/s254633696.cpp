#include <bits/stdc++.h>

#define int long long

using namespace std;

int d[101];
int ans, n;
map <pair <string, string>, int> used;
char a[1001];

void go (int v) {
	if (v > n) {
		string s1 = "";
		string s2 = "";
		for (int i = 1;i <= n;i ++) {
			if (d[i] == 0) s1 += a[i];
			else s2 += a[i];
		}
		used[make_pair (s1, s2)] ++;
		return;
	}
	d[v] = 0;
	go (v + 1);
	d[v] = 1;
	go (v + 1);
}

void go1 (int v) {
	if (v > n + n) {
		string s1 = "";
		string s2 = "";
		for (int i = n + 1;i <= n + n;i ++) {
			if (d[i] == 0) s1 += a[i];
			else s2 += a[i];
		}
		reverse (s1.begin (), s1.end ());
		reverse (s2.begin (), s2.end ());
		ans += used[make_pair (s2, s1)];
		return;
	}
	d[v] = 0;
	go1 (v + 1);
	d[v] = 1;
	go1 (v + 1);
}
		
 main () {
	cin >> n;
	for (int i = 1;i <= n + n;i ++) {
		cin >> a[i];
	}
	go (1);
	go1 (n + 1);
	cout << ans;   
	return 0;
}