#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int X;
	cin >> X;
	int p = sqrt(X);
	if (X == p*p) {
		cout << X << endl;
		return 0;
	}
	int ans = 1;
	for (int i = 2; i <= p; i++) {
		int test = 1;
		int j = 2;
		while (test <= X) {
			test = pow(i,j);
			j++;
		}
		ans = max(ans,test/i);
	}
	cout << ans << endl;

	return 0;
}
