#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, n) for(int i = 1; i <= n; i++)
template<class T> inline int chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline int chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1<<30;
const ll LINF = 1LL<<58;
const int mod = 1000000007;

map<ll, int> prime_factor(ll n) {
    map<ll, int> ret;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if (n != 1) ret[n] = 1;
    return ret;
}

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        auto m = prime_factor(i);
        for (int j = 2; j < 101; j++) mp[j] += m[j];
    }
    int p75 = 0, p25 = 0, p15 = 0, p5 = 0, p3 = 0;
    for (int i = 0; i < 100; i++) {
        if(mp[i] >= 74) p75++;
        if(mp[i] >= 24) p25++;
        if(mp[i] >= 14) p15++;
        if(mp[i] >= 4) p5++;
        if(mp[i] >= 2) p3++;
    }
    cout << p75 + p25 * (p3 - 1) + p15 * (p5 - 1) + p5 * (p5 - 1) * (p3 - 2) / 2 << endl;
    return 0;
}
