#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<numeric>
#include<math.h>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    int n;
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    rep(i, n) {
        if ( a[i] == b[i] && b[i] == c[i] ) {
            continue;
        }
        else if ( a[i] == b[i] || b[i] == c[i] || a[i] == c[i] ) {
            ++ans;
        }
        else {
            ans += 2;
        }
    }
    cout << ans << endl;
    return 0;
}
