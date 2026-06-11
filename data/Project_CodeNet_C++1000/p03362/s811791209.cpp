#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

#include <bits/stdc++.h>
using namespace std;

const ll mod = 1e9 + 7;

const ll INF = 1e15;

class Primes {
private:
	vector<int> Prime_Number;
	vector<bool> is_prime_;
public:
	Primes(int N) {
		is_prime_.resize(N + 1, true);
		is_prime_[0] = is_prime_[1] = false;
		for (int i = 0; i < N + 1; i++) {
			if (is_prime_[i]) {
				Prime_Number.push_back(i);
				for (int j = 2 * i; j <= N; j += i) is_prime_[j] = false;
			}
		}
	}
	int operator[](int i) { return Prime_Number[i]; }
	int size() { return Prime_Number.size(); }
	int back() { return Prime_Number.back(); }
	bool isPrime(int q) { return is_prime_[q]; }
};

int main() {
	ll n;
	cin >> n;
	vector<ll> all;
	Primes prime(55555);
	for (int i = 0; i < prime.size(); i++) {
		auto p = prime[i];
		if (p % 5 == 1) {
			all.push_back(p);
		}
	}
	rep(i, n) {
		cout << all[i] << " ";
	}
	cout << endl;
	return 0;
}
