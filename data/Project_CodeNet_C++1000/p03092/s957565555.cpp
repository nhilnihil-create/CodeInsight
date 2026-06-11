#include <bits/stdc++.h>

#define mp make_pair
#define X first
#define Y second
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FOD(i, a, b) for(int i = a; i >= b; i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int N = 5010;
const ll INF = 1e18;

/// x ->
/// y <-

int n, a[N];
int cnt[N][N];
ll x, y, F[N][N];

int main(){
    if (fopen("inp.txt", "r")){
        freopen("inp.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> x >> y;
    FOR(i, 1, n)
        cin >> a[i];

    FOR(i, 0, n)
        FOR(j, 0, n)
            F[i][j] = INF;

    F[0][0] = 0;
    FOR(i, 0, n - 1)
        FOR(val, 0, n)
            if (val < a[i + 1]){
                F[i + 1][val] = min(F[i + 1][val], F[i][val] + x);
                F[i + 1][a[i + 1]] = min(F[i + 1][a[i + 1]], F[i][val]);
            } else {
                F[i + 1][val] = min(F[i + 1][val], F[i][val] + y);
            }

    ll ans = INF;

    FOR(i, 0, n)
        ans = min(ans, F[n][i]);
    cout << ans;

    return 0;
}

