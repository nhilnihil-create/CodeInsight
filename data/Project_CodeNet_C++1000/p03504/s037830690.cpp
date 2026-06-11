

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

int a[35][100005];

int main(void) {
    int N, C;
    cin >> N >> C;
    rep(i, 0, N) {
        int s, t, c;
        scanf("%d %d %d", &s, &t, &c);
        a[c][s] += 1; 
        a[c][t+1] += -1;
    }

    rep(i, 1, C+1) rep(j, 1, 100005) {
        a[i][j] += a[i][j-1]; 
    }

    int ans = -1; 
    rep(i, 1, 100005) {
        int t = 0;
        rep(j, 1, C+1) if (a[j][i]>=1) t++; 
        ans = max(ans, t);
    }

    printf("%d\n", ans);

	return 0;
}
