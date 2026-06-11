#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <list>
#include <iomanip>
#include <queue>
#include <cmath>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;
typedef pair<ll, ll> p;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const long long mod = 1e9 + 7;
ll dx[] = { 1,0 };
ll dy[] = { 0,1 };

int main() {

    ll N, M;
    cin >> N >> M;

    vector <ll> A;

    ll tmp;

    rep(i, N) {
        cin >> tmp;
        A.push_back(tmp);
    }

    vector<p> cb;
    rep(i, M) {
        ll b, c;
        cin >> b >> c;
        cb.emplace_back(c, b);
    }

    sort(A.begin(), A.end(), greater<>());
    sort(cb.begin(), cb.end(), greater<>());
    
    cb.emplace_back(0, 1);

    ll id1 = 0, id2 = 0, cnt = 0;
    vector<ll> x;

    while(cnt < N) {
        if (A[id1] > cb[id2].first) {
            x.push_back(A[id1]);
            cnt++;
            id1++;
        }
        else {
            rep(i, cb[id2]. second) {
                x.push_back(cb[id2].first);
                cnt++;
            }
            id2++;
        }
    }

    ll ans = 0;

    rep(i, N) {
        ans += x[i];
    }

    cout << ans;

    return 0;
}