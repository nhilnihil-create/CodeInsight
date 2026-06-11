#include<bits/stdc++.h>

typedef long long ll;
typedef std::pair<ll, ll> P;
typedef std::tuple<ll, ll, ll> t3;
constexpr ll INF = 1e15;
constexpr ll mod = 1e9+7;

#define rep(i,n) for(int i = 0; i < int(n); i++)
using namespace std;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }


class Divisor {
private:
	vector<ll> F;
public:
	Divisor(ll N) {
		for (ll i = 1; i * i <= N; i++) {
			if (N % i == 0) {
				F.push_back(i);
				if (i * i != N) F.push_back(N / i);
			}
		}
		sort(begin(F), end(F));
	}
	int size() { return F.size(); }
	ll operator[](int k) { return F[k]; }
	const vector<ll>& factors() { return F; }
};

int main() {
	string s;
	cin >> s;
	int n = s.size();
	vector<bool> ws(n, 0);
	rep(i, n) {
		ws[i] = s[i] == 'W';
	}
	int j = 0;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		if (ws[i]) {
			ll dist = i - j;
			sum += dist;
			j++;
		}
	}
	cout << sum << endl;
	return 0;
}
