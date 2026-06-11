#include <iostream>
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
    vector<pair<int, int>> ab(m);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        ab[i] = {b, a};
    }
    sort(ab.begin(), ab.end());
    int r = ab[0].first;
    int ans = 1;
    for ( int i = 1; i < m; ++i ) {
//        cout << "r: " << r << "ab[i].second:  " << ab[i].second << endl;
        if ( ab[i].second >= r ) {
            ++ans;
            r = ab[i].first;
        }
//        cout << "test" << " " << i << " " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
