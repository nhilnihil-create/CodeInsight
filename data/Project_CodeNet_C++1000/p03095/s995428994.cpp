#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

string alphabet="abcdefghijklmnopqrstuvwxyz";
const ll MOD = 1000000007;
int main(){
	ll n;
	cin >> n;
	string s;
	cin >> s;
	map<char,int> mp;
	rep(i,s.size()){
		mp[s[i]]++;
	}
	ll ans = 1;
	rep(i,26){
		ans *= mp[alphabet[i]] + 1;
		ans %= MOD;
	}
	ans--;
	cout << ans % MOD << endl;
    return 0;
}

