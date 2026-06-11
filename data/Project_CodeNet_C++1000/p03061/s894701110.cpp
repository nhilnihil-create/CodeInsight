#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 5;
int pre[N], suf[N], arr[N];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef ONLINE_JUDGE
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);
#endif
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){

		cin >> arr[i];
		pre[i] = arr[i];
		if(i)
			pre[i] = __gcd(pre[i], pre[i - 1]);
	}
	for(int i = n - 1; i >= 0; i--){
		suf[i] = arr[i];
		if(i != n - 1)
			suf[i] = __gcd(suf[i], suf[i + 1]);
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(i == 0){
			ans = max(ans, suf[i + 1]);
		}
		else if(i == n - 1){
			ans = max(ans, pre[i - 1]);
		}
		else
			ans = max(ans, __gcd(pre[i - 1], suf[i + 1]));
	}
	cout << ans;
	return 0;
}
