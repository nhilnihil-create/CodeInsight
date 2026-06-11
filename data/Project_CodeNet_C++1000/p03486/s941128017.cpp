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

int main() {
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.rbegin(), t.rend());
    int n = min(s.size(), t.size());
    rep(i, n) {
        if (s[i] > t[i]) {
            cout << "No" << endl;
            return 0;
        }
        if (s[i] < t[i]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    if (s.size() < t.size()) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}
