#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int) (n); i++)
long long int INF=1001001000;

int main() {
	int r,d,x; cin >> r >> d >> x;
	int ans = x;
	rep(i,10) {
		ans=r*ans-d;
		cout << ans << endl;
	}
}