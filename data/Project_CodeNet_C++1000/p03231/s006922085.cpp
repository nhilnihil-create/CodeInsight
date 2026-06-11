#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstdint>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

ll gcd(ll a, ll b) {
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

int main() {
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;
    ll P = lcm(N, M);
    if(N < M) {
        swap(N, M);
        swap(S, T);
    }
    ll a = P / N, b = P / M;
    for(int i = 0; i < M; i++) {
        if((b * i) % a == 0) {
            if(S[(b * i) / a] != T[i]) {
                cout << "-1" << endl;
                return 0;
            }
        }
    }
    cout << P << endl;
    return 0;
}