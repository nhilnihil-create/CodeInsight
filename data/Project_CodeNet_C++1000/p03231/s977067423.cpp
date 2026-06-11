#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i, s, n) for (int i = s; i < (n); i++)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define maxs(x,y) x = max(x, y)
#define mins(x,y) x = min(x, y)
using namespace std;
using ll = long long;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
const ll INF = MOD * MOD;
const int inf = (1<<29);

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {

    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;
    ll L = lcm(N, M);
    ll g = gcd(N, M);

    for(int i = 0; i < g; i++) {
        if (S[i*N/g] != T[i*M/g]) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << L << endl;

    //cout << ans << endl;
    return 0;
}