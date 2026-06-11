#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<numeric>
#include<math.h>
#include<deque>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    int n;
    cin >> n;
    vector<int> b(n);
    rep(i, n) cin >> b[i];
    vector<int> ans;
    int sz = n;
    while(!b.empty()) {
        int best = -1;
        rep(i, sz) {
            if ( b[i] == i + 1 ) {
                best = i;
            }
        }
        if ( best == -1 ) {
            cout << -1 << endl;
            return 0;
        }
        ans.push_back(best+1);
        b.erase(b.begin()+best);
        --sz;
    }

    reverse(ans.begin(), ans.end());
    for ( int v : ans ) {
        cout << v << endl;
    }
    return 0;
}
