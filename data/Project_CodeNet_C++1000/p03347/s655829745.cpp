#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int i = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int i = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define MP make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1 << 30;
const ll LINF = 1LL << 61;
const int MOD = 1e9 + 7;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll res = 0;
    rep(i, N) { cin >> A[i]; }
    if(A[0] != 0) {
        cout << -1 << endl;
        return 0;
    }

    for(int i = 1; i < N; i++) {
        if(A[i] - A[i - 1] > 1) {
            cout << -1 << endl;
            return 0;
        } else {
            if(A[i] <= A[i - 1]) {
                res += A[i];
            } else {
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}