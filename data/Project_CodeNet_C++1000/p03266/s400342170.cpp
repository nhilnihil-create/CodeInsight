//----------------------------------------------------------------------
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    int n, k;
    cin >> n >> k;

    ll ans1 = 0;
    ll ans2 = 0;
    for(int i = 1; i <= n; ++i) {
        if(i%k == 0) ans1++;
        else if(i%k == k/2) ans2++;
    }

    if(k%2==0) {
        cout << ans1 * ans1 * ans1 + ans2 * ans2 * ans2 << endl;
    }else {
        cout << ans1 * ans1 * ans1 << endl;
    }
    return 0;
}
