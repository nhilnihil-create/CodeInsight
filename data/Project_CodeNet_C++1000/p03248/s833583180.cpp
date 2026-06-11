#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

char str[N];

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> str + 1;
	int n = strlen(str + 1);
	if (str[n] == '1' || str[1] == '0') {
		cout << "-1\n";
		return 0;
	}
	for (int i = 1; i < n; i++) if (str[i] != str[n - i]) {
		cout << "-1\n";
		return 0;
	}
	
	int rt = 1, v = 1, bf = 1;
	for (int i = 2; i <= n; i++) if (str[i] == '1') {
		cout << v + 1 << " " << rt << "\n";
		bf++;
		rt = ++v;
		for (int j = 0; j < i - bf; j++) cout << rt << " " << (++v) << "\n"; bf = i;
	}
	cout << v + 1 << " " << rt << "\n";
	
	return 0;
}