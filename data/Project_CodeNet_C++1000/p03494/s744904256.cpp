#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	ll A[N];
	rep(i,N) cin >> A[i];

	int ans = 0;
	bool con = true;
	while (con) {
		rep(i,N) {
			if (A[i]%2 == 0) A[i] /= 2;
			else {
				con = false;
				break;
			}
		}
		ans += 1;
	}	
	ans -= 1;
	cout << ans << endl;
	return 0;
}
