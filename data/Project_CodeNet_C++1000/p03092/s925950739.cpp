#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <deque>
#include <queue>

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define FOR(i, a, b) for(int i=a, loop=b; i<=loop; ++i)
#define REV(i, a, b) for(int i=a, loop=b; i>=loop; --i)
#define mize(a, b) a = min(a, b)
#define maxi(a, b) a = max(a, b)
#define shl(k) ((k) << 1)
using namespace std;

const int N = 5001;
int n, a[N], c[N][N], v[N], A, B;
int64_t f[N][N], INF = 1e15;

int main()
{
    ios::sync_with_stdio(); cin.tie(0);

    cin >> n >> A >> B;
    FOR(i, 1, n) {
        cin >> a[i];
        v[a[i]] = i;
    }

    FOR(i, 1, n) {
        c[i][i] = a[i];
        FOR(j, i+1, n) c[i][j] = max(c[i][j-1], a[j]);
    }

    FOR(i, 0, n) FOR(j, 1, n) f[i][j] = INF;
    f[0][1] = (a[1]==1 ? 0 : B);
    f[v[1]][1] = 0;


    FOR(j, 1, n-1) FOR(i, 0, n) {
        ///cout << i <<' '<< j <<' '<< f[i][j] << endl;
        if (v[j+1] <= i)
            mize(f[i][j+1], f[i][j]+A);
        else {
            mize(f[v[j+1]][j+1], f[i][j]);
            mize(f[i][j+1], f[i][j] + (c[i+1][v[j+1]-1] > j+1 ? B : 0));
        }
    }

    int64_t ans = INF;
    FOR(i, 0, n) mize(ans, f[i][n]);
    cout << ans;
}
