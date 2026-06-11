#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

template<typename T>
static inline void chmin(T & ref, const T  value) {
    if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T & ref, const T value) {
    if (ref < value) ref = value;
}

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
    vector<int>& primes() { return Prime_Number; }
    int size() { return Prime_Number.size(); }
    int back() { return Prime_Number.back(); }
    bool isPrime(int q) { return is_prime_[q]; }
};

int main() {

    Primes pr(1e5 + 1);
    vector<int> match(1e5 + 1, 0);
    for (auto p : pr.primes()) {
        auto c = p * 2-1;
        if (c > 1e5) break;
        if (pr.isPrime(c)) {
            match[c]=1;
        }
    }
    vector<int> sums(1e5 + 2, 0);
    for (int i = 0; i < 1e5 + 1; i++) {
        sums[i + 1] = sums[i] + match[i];
    }
    int q;
    cin >> q;
    vector<int> ans;
    rep(i, q) {
        int l, r;
        cin >> l >> r;
        auto a = sums[r+1] - sums[l];
        ans.push_back(a);
    }
    for (auto a : ans) {
        cout << a << endl;
    }
    return 0;
}

