

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;

int ans = 1000000000;
int N, C;
int D[505][505], a[5][35];

int main(void) {
    cin >> N >> C;
    rep(i, 1, C+1) rep(j, 1, C+1) scanf("%d", &D[i][j]);
    rep(i, 1, N+1) rep(j, 1, N+1) {
        int c;
        scanf("%d", &c);
        a[(i+j)%3][c]++;
    }

    rep(i, 1, C+1) {
        rep(j, 1, C+1) {
            if (i==j) continue;
            rep(k, 1, C+1) {
                if (k==i || k==j) continue;
                int sum = 0;
                rep(l, 1, C+1) {
                    sum += D[l][i]*a[0][l]+D[l][j]*a[1][l]+D[l][k]*a[2][l];
                }
                ans = min(ans, sum);

            }
        }
    }
    

    printf("%d\n", ans);

	return 0;
}
