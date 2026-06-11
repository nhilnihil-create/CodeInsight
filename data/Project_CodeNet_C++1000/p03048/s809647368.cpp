#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    int ans = 0;
    rep(i, n+1) rep(j, n+1) {
        if ( n - i * r - j * g < 0 ) continue;
        if ( ( n - i * r - j * g ) % b == 0 ) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
