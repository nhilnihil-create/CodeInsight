#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n; i >= 0; --i)
#define FOR(i, n, m) for (int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

typedef long long ll;
/**
 * C問以降は ll を使う.
 * double型にするのを忘れない.
 * nC2の求め方 (1/2)*n*(n-1)
 * vector<型> 変数名(要素数, 初期値)
 */
int main()
{
    int N, H, W;
    cin >> N >> H >> W;
    int cnt = 0;
    REP(i, N) {
        int a, b;
        cin >> a >> b;
        if(a >= H && b >= W) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}