#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<string>
#include<numeric>
using namespace std;
typedef long long ll;
//ll mod = 1e9+7;
ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n, k;
    cin >> n >> k;
    vector<ll> a_accum(n+1);
    a_accum[0] = 0;
    rep(i, n) {
        ll a;
        cin >> a;
        a_accum[i+1] = a_accum[i] + a;
    }
    vector<ll> check_num_list;
    rep(i, n) {
        for ( int j = i; j < n; ++j ) {
            ll tmp_num = a_accum[j+1] - a_accum[i];
            check_num_list.push_back(tmp_num);
        }
    }
    ll ans = 0;
    for ( int i = 39; i >= 0; --i ) {
        ans += 1LL<<i;
        int cnt = 0;
        for ( auto tmp_num : check_num_list ) {
            if ( ( ans & tmp_num ) == ans ) {
                ++cnt;
            }
        }
        if ( cnt < k ) {
            ans -= 1LL<<i;
        }
    }
    cout << ans << endl;
    return 0;
}
