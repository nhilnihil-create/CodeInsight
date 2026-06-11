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
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    int ans = 0;
    for ( int l = 0; l <= n; ++l ) {
        for ( int r = 0; r <= n; ++r ) {
            if ( l + r > k ) continue;
            if ( l + r > n ) continue;
            priority_queue<int, vector<int>, greater<int>> q;
            int sum = 0;
            rep(i, l) q.push(v[i]);
            rep(i, r) q.push(v[n-i-1]);
            int d = k - l - r;
            rep(c, d) {
                if ( q.empty() ) break;
                if ( q.top() >= 0 ) break;
                q.pop();
            }
            while(!q.empty()) {
                sum += q.top();
                q.pop();
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;
}
