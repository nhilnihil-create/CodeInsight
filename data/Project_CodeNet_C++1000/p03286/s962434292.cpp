#include <bits/stdc++.h>

using namespace std;

template <class T>
using lim = numeric_limits<T>;

typedef long long ll;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	string ans = !n ? "0" : "";
	while(n){
		ans += '0'+(n&1);
		if (n < 0 && n&1)  n = n/-2 + 1;
		else n /= -2;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";
}