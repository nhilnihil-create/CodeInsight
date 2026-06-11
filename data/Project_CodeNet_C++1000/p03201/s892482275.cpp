#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
#include <bits/extc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
	 ios::sync_with_stdio(0);
	 cin.tie(0);
	 cout.tie(0);
	 ll n;
	 cin >> n;
	 vi a;
	 a.resize(n);
	 for(auto &i :a) cin >> i;
	 sort(all(a));
	 reverse(all(a));
	 gp_hash_table<ll, int> cnt;
	 ll ans = 0;
	 ll x;
	 for(auto i : a) {
		 cnt[i]++;
	 }
	 for(auto i : a) {
		 if(!cnt[i]) continue;
		 cnt[i]--;
		 ll x = 1;
		 while(x <= i) x<<=1;
		 if(cnt[x-i]) cnt[x-i]--, ans++;
	 }
	 cout << ans;
	 return 0;
}
