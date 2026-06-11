#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n, m;
    cin >> n >> m;
    int ans = 1;
    for ( int i = 1; i * i <= m; ++i ) {
        if ( m % i == 0 ) {
            if ( m / i >= n ) {
                ans = max(ans, i);
            }
            if ( i >= n ) {
                ans = max(ans, m / i);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
