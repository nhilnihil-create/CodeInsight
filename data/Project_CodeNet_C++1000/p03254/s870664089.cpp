#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	ll x;
	cin >> N >> x;
	ll a[N];
	rep(i,N) cin >> a[i];
	sort(a,a+N);
	int ans = N-1;
	rep(i,N) {
		x -= a[i];
		if (x==0) {
			ans = i+1;
			break;
		}
		else if (x<0) {
			ans = i;
			break;
		}
	}
	cout << ans << endl;


	return 0;
}
