#include <bits/stdc++.h>
#define Data_Nerd ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define files freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;
using ll = long long;

const int N = 1e5 + 1;

ll arr[N];

int main() {
	Data_Nerd
	int n, m; scanf("%d%d", &n, &m);

	for(int i = 0; i < n; ++i)
		scanf("%lld", arr + i);

	arr[0] %= m;

	for(int i = 1; i < n; ++i) {
		arr[i] = (arr[i] + arr[i - 1]) % m;
	}

	map <ll, ll> freq;

	for(int i = 0; i < n; ++i) {
		++freq[arr[i]];
	}

	ll ans = 0;

	for(auto i : freq) {
		ans += i.second * (i.second - 1) / 2;
		if(i.first == 0)
			ans += i.second;
	}

	cout << ans;
}
