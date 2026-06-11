#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    int n;
    cin >> n;
    int ans = 0;
    int cnt = 1;
    int a = 0;
    int pre_a = 0;
    rep(i, n) {
        pre_a = a;
        cin >> a;
        if ( i == 0 ) continue;
        if ( a == pre_a ) ++cnt;
        else {
            ans += cnt / 2;
            cnt = 1;
        }
        if ( i == n - 1 ) {
            ans += cnt / 2;
            cnt = 1;
        }
    }
    cout << ans << endl;
    return 0;
}
