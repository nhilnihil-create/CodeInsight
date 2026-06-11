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

ll ans, a[200005];
int n;

int main(void) {
    cin >> n;
    rep(i, 0, n) scanf("%lld", &a[i]);

    if (a[0]>0) {
        puts("-1");
        return 0;
    }

    rep(i, 1, n) if (a[i]>0) {

        if (a[i-1]==a[i]-1) ans++;
        else if (a[i-1]>=a[i]) ans += a[i];
        else if (a[i-1]<a[i]-1) {
            puts("-1");
            return 0;
        }
        
    }
    cout << ans << endl;

	return 0;
}
