#include<bits/stdc++.h>
using namespace std;
int xi[100010];
long long pos[100010], neg[100010];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> xi[i];
	}
	int a = 0;
	for (int i = 1; i <= n; ++i) {
		if (xi[i] >= 0) {
			++a;
			if (a == 1) {
				pos[a] = xi[i];
				continue;
			}
			pos[a] = pos[a - 1] + abs(xi[i] - xi[i - 1]);
		}
	}
	int b = 0;
	for (int i = n; i >= 1; --i) {
		if (xi[i] < 0) {
			++b;
			if (b == 1) {
				neg[b] = -xi[i];
				continue;
			}
			neg[b] = neg[b - 1] + abs(abs(xi[i]) - abs(xi[i + 1]));
		}
	}
	long long answer = 9e18;
	for (int i = 0; i <= k; ++i) {
		if (min(a, i) + min(k - i, b) == k) {
			//cout << i << " " << pos[min(a, i)] << " " << neg[min(k - i, b)] << '\n';
			answer = min(answer, 2 * pos[min(a, i)] + neg[min(k - i, b)]);	
		}
		
	} 
	for (int i = 0; i <= k; ++i) {
		if (min(b, i) + min(k - i, a) == k) {
			//cout << i << " " << pos[min(a, i)] << " " << neg[min(k - i, b)] << '\n';
			answer = min(answer, pos[min(k - i, a)] + 2 * neg[min(i, b)]);	
		}
		
	} 
	cout << answer;
}