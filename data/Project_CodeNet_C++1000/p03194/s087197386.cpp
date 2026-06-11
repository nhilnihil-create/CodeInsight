#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

int main() {
	ll N, P;
	cin >> N >> P;
	if(N >= 40) {
		cout << 1 << endl;
		return 0;
	}
	if(N == 1) {
		cout << P << endl;
		return 0;
	}
	int ans = 1;
	for(int i = 2; pow((ll)i, N) <= P; i++) {
		int num = 0;
		while(P % i == 0) {
			P /= i;
			num++;
		}
		ans *= pow(i, num / N);
	}
	cout << ans << endl;
}
