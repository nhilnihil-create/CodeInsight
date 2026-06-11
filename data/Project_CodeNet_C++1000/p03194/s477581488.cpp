#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include<cmath>
#include<iomanip>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;
ll ans = 1;
int main() {
	ll N, P;
	cin >> N >> P;
	if (N == 1) {
		cout << P << endl;
	}
	else {
		for (ll i = 1; pow(i, N) <= P; i++) {
			if (P % (ll)pow(i, N) == 0) ans = i;
		}
		cout << ans << endl;
	}
	return 0;
}

