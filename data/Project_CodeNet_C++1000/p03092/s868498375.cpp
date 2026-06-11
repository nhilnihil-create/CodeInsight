#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, int> ri3;
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
#define SZ(x) (int)(x).size()
#define ALL(x) begin(x), end(x) 
#define REP(i, n) for (int i = 0; i < n; ++i) 
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, a, b) for (int i = a; i >= b; --i)

const int N = 5005;

int n, a, b;
int arr[N], p[N];
ll res[N][N];

int main() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> a >> b;
    FOR(i,1,n){
        cin >> arr[i];
        p[arr[i]] = i;
    }

    memset(res[n+1], 0, sizeof res[n+1]);
    RFOR(i, n, 1) {
        ll minB[p[i]], minA[n+1];
        minB[p[i]-1] = res[i+1][p[i]-1];
        RFOR(y, p[i]-2, 0) minB[y] = min(minB[y+1], res[i+1][y]);

        minA[n] = res[i+1][n];
        RFOR(y, n-1, 0) minA[y] = min(minA[y+1], res[i+1][y]);


        FOR(x, 0, n) {
            res[i][x] = 1e18;

            //res[i][x] = min(minB[p[i]-1] + b, minA[p[i]] + a);
            res[i][x] = minA[max(x, p[i])] + a;
            if (x < p[i]) res[i][x] = min(res[i][x], minB[x] + b);
            //FOR(y,x,n){
            //    if (y < p[i]) res[i][x] = min(res[i][x], res[i+1][y] + b);
            //    else res[i][x] = min(res[i][x], res[i+1][y] + a);
            //}
            if (p[i] > x) res[i][x] = min(res[i][x], res[i+1][p[i]]);
            //cout << i << " " << x << " :: " << res[i][x] << '\n';
        }
    }
    cout << res[1][0] << '\n';
}