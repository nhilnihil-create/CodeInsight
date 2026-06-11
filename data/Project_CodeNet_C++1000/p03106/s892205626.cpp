#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
#define all(x) x.begin(), x.end()

signed main() {
	int a, b, k;
	cin >> a >> b >> k;
	for(int i = min(a,b); i >= 1; i--){
		if(a%i == 0 && b%i == 0){
			k--;
			if(k == 0){
				cout << i << endl;
				return 0;
			}
		}
	}
	return 0;
}
