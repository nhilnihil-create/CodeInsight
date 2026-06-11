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
	ll n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	
	ll l = lcm(n, m);
	ll g = gcd(n, m);
	
	for(ll i = 0; i < g; ++i){
		if(s[i * n / g] != t[i * m / g]){
			cout << -1 << endl;
			return 0;
		}
	}
	cout << l << endl;
	
	return 0;
}

