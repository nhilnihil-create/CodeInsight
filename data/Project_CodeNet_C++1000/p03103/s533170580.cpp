#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i > (b); i--)
#define ALL(a) (a).begin(), (a).end()

int main() {
    ll N, M;
    cin >> N >> M;
    pll AB[N];
    REP(i, N) {
        ll A, B;
        cin >> A >> B;
        AB[i] = {A, B};
    }
    sort(AB, AB + N);
    ll ans = 0;
    REP(i, N) {
        if (M <= 0) break;
        ans += AB[i].first * min(AB[i].second, M);
        M -= AB[i].second;
    }
    cout << ans << endl;
    return 0;
}