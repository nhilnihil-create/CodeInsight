#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
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

int main() {
    ll N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;
    ll Xlen = N * (M / __gcd(N, M));
    map<ll, char> check;
    ll Sb = Xlen / N;
    ll Tb = Xlen / M;
    for(ll i = 0; i < N; i++) {
        check[Sb * i] = S[i];
    }
    int ok = 1;
    for(ll i = 0; i < M; i++) {
        if(!check.count(Tb * i))
            continue;
        if(check[Tb * i] != '.' && check[Tb * i] != T[i])
            ok = 0;
    }
    if(ok) {
        cout << Xlen << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}