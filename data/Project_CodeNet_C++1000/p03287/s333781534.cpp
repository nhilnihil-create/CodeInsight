#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6;
int n, m, a[maxN];
long long s[maxN], s_t, ans;
map <int, int> mp;

int main(){
	cin >> n >> m;
	mp[0] = 1;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i){
		s_t += a[i];
		s[i] = s_t;
		int r = s[i] % m;
		ans += mp[r];
		mp[r]++;
	}
	cout << ans;
}