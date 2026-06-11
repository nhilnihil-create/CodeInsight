#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int A, B, C, X;
	cin >> A >> B >> C >> X;
	int ans = 0;
	for (int i = 0; i <= min(X/500, A); i++) {
		for (int j = 0; j <= min((X-500*i)/100, B); j++) {
			for (int k = 0; k <= min((X-500*i-100*j)/50, C); k++) {
				int p = 500*i + 100*j + 50*k;
				if (p == X) ans++;	
			}
		}
	}
	cout << ans << endl;
	return 0;
}
