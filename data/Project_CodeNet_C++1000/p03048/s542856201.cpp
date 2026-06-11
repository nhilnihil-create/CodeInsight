#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	int r, g, b, n, ans = 0;
	scanf("%d%d%d%d", &r, &g, &b, &n);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			int third = r * i + g * j;
			if (n - third >= 0 && (n - third) %b == 0) {
				ans++;
			}
		}
	}
	printf("%d", ans);
}
