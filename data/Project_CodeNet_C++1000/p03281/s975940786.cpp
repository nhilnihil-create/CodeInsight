#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int N;
	cin >> N;
	int ans = 0;
	for(int i = 1; i <= N; i++) {
		if(i % 2 == 0) continue;
		int cnt = 0;
		for(int j = 1; j <= i; j++)
			if(i % j == 0) cnt++;
		if(cnt == 8) ans++;
	}
	cout << ans << "\n";
}