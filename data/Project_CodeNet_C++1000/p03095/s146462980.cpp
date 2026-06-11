#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;
using ll = long long;
static const int INF = 1000000000;
static const ll MOD = 1000000007;

ll gcd(ll a, ll b){return b!=0 ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}

int main(){
	int n;
	string s;
	cin >> n >> s;
	
	vector<ll> c(26, 1);
	rep(i, n){
		c[(int)(s[i] - 'a')]++;
	}
	
	ll ans = 1;
	rep(i, 26){
		ans = ans * c[i] % MOD;
	}
	ans--;
	
	cout << ans << endl;
	return 0;
}

