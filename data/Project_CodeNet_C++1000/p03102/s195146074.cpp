#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 50;
int n, m, c;
int b[N];

int main() {
	
	cin >> n >> m >> c;
	for(int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int tmp = 0, x;
		for(int j = 1; j <= m; j++) {
			scanf("%d", &x);
			tmp += x * b[j];
		}
		tmp += c;
		if(tmp > 0) {
			ans++;
			//break;
		}
	}
	cout << ans << endl;
	return 0;
} 