#include <bits/stdc++.h>
#define rep(i , n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int main() {
	double t , ans =0;
	int n , k , now;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		t = 1.0 / n;
        now = i;
		while(now < k){
			now *= 2;
            t /= 2;
		}
		ans += t;
	}
    cout << fixed << setprecision(20) << ans << endl;
	return 0;
}