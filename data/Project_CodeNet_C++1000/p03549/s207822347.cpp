#include<bits/stdc++.h>

typedef long long ll;
typedef std::pair<ll, ll> P;

constexpr ll INF = 1e15;
constexpr ll mod = 1e9+7;

#define rep(i,n) for(int i = 0; i < int(n); i++)
using namespace std;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
    ll n, m;
    cin >> n >> m;
    ll count = 1LL << m;
    ll sum = (m * 1900) + (n - m) * 100;
    sum *= count;
    cout << sum << endl;
    return 0;
}
