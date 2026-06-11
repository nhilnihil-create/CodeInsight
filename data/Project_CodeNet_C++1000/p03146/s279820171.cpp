#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	ll s;
	cin >> s;
	bool used[100000];
	for(int i = 0; i < 100000; i++) used[i] = false;
	int m = 1;
	while(true) {
		if(used[s]) {
			cout << m << "\n";
			return 0;
		}
		used[s] = true;
		m++;
		if(s % 2 == 0)
			s /= 2;
		else
			s = 3 * s + 1;
	}
	return 0;
}
