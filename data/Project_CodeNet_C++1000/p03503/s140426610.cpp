#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;

int N;
vector<vector<ll>> F(10, vector<ll>(10)), P(10, vector<ll>(11));
ll ans = -INF;

void rec(vector<ll> &A, int depth) {
    if (depth == 10) {
        ll tmp = 0;
        bool judge = 0;
        rep(i, N) {
            ll cnt = 0;
            rep(j, 10) {
                if (A[j] == 1)
                    judge = 1;
                if (F[i][j] == A[j] && A[j] == 1)
                    cnt++;
            }
            tmp += P[i][cnt];
        }

        if (judge)
            ans = max(ans, tmp);
        return;
    }

    vector<ll> AA = A;
    A.push_back(0);
    rec(A, depth + 1);
    A.pop_back();
    A.push_back(1);
    rec(A, depth + 1);
    A.pop_back();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;

    F.resize(N, vector<ll>(10));
    P.resize(N, vector<ll>(11));
    rep(i, N) {
        rep(j, 10) { cin >> F[i][j]; }
    }

    rep(i, N) {
        rep(j, 11) { cin >> P[i][j]; }
    }

    vector<ll> A;
    ll count = 0;
    rec(A, 0);

    cout << ans << endl;

    return 0;
}