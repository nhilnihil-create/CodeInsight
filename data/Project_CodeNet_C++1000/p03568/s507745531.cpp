#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	ll odd = 1;
	ll ans = 1;
	rep(i,N) {
		int a;
		cin >> a;
		if (a%2 == 0) odd *= 2;
		ans *= 3;
	}
	ans -= odd;
	cout << ans << endl;

	return 0;
}
