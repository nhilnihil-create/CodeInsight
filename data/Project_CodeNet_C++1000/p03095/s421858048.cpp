# include <bits/stdc++.h>
# define ll long long
using namespace std;
const ll MOD = 1e9 + 7;
string s;
ll ans, cnt[26], n; 
int main(){
	cin >> n >> s;
	for(int i = 0; i < n; ++i){
		ll ways = 1;
		for(int j = 0; j < 26; ++j){
			if(s[i] - 'a' == j)continue;
			ways = ways * (cnt[j] + 1) % MOD;
		}
		ans += ways;
		ans %= MOD;
		cnt[s[i] - 'a'] ++;
	}
	cout << ans << '\n';
}