#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int R, G, B, N;
	cin >> R >> G >> B >> N;
	ll ans = 0;
	int r_max = (N+R-1)/R;
	int g_max = (N+G-1)/G;
	rep(i,r_max+1)rep(j,g_max+1){
		int k = (N - i*R - j*G)/B;
		if (k < 0 ) break;
		if (i*R + j*G + k*B == N) ans++;
	}
	cout << ans << endl;
	return 0;
}
