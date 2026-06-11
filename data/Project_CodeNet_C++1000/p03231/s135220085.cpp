#include<bits/stdc++.h>
#include<numeric>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i <= (ll)(n); ++i)
#define MAX 500000001000000000
#define MOD 1000000007
typedef long long  ll;

using namespace std;

ll ans;

// 最大公約数のll版
ll gcd(ll a, ll b)
{
	if (a < b)
		swap(a, b);
	return b == 0 ? a : gcd(b, a % b);
}

// 最小公倍数のll版
ll lcm(ll a, ll b)
{
	return a * b / gcd(a, b);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N, M;
	cin >> N >> M;

	string S, T;
	cin >> S >> T;

	ll g = gcd(N, M);
	ll l = lcm(N, M);

	ll index = 0;
	while (true){
		if(S[index/M] != T[index/N]){
			//cout << index << endl;
			cout << "-1" << endl;
			return 0;
		}
		else{
			index += l;
			if(index/M >= N || index/N >= M){
				cout << l << endl;
				return 0;
			}
		}
	}

	return 0;
}