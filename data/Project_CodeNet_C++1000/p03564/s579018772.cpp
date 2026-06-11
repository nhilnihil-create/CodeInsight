#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)

int main() {
	int n,k; cin >> n >> k;
	int ans=1;
	rep(i,n) {
		if(ans*2<=ans+k) ans*=2;
		else ans+=k;
	}
	cout << ans << endl;
}