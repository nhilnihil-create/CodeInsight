#include <bits/stdc++.h>
#define LL long long
#define PII pair<int,int>
using namespace std;
const int MAXN = 200000;
const int INF = 1e9 + 5;

#define v first
#define pos second

int a[MAXN+5], b[MAXN+5], N;
PII diff[MAXN+5];
LL pre[MAXN+5];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	LL ans = 0;
	int minv = INF;;
	bool eq = true;
	for (int i = 0; i < N; i++) {
		cin >> a[i] >> b[i];
		if (a[i] != b[i]) eq = false;
		if (a[i] > b[i]) minv = min(b[i], minv);
		ans += a[i];
	}
	
	if (eq) {
		cout << "0\n";
		return 0; 
	}
	
	ans -= minv;
	cout << ans << "\n";
	
	/**** Note MAXN ****/
}
