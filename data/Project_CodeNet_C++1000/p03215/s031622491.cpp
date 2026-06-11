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
//    rep(i, n+1) {
//        cout << a_accum[i] << endl;
//    }
    vector<vector<ll>> keta_one_list(40);
    rep(i, n) {
        for ( int j = i; j < n; ++j ) {
            ll tmp_num = a_accum[j+1] - a_accum[i];
            int check_idx = 0;
            while(1) {
//                cout << tmp_num << " " << (1LL<<check_idx) << endl;
                if ( (1LL<<check_idx) > tmp_num ) {
                    break;
                }
                if ( tmp_num & (1LL<<check_idx) ) {
                    keta_one_list[check_idx].push_back(tmp_num);
//                    cout << keta_one_list[check_idx].back() << endl;
                }
                ++check_idx;
            }
        }
    }
//    rep(i, 10) {
//        cout << i << ": ";
//        for ( auto tmp_num : keta_one_list[i] ) {
//            cout << tmp_num << " ";
//        }
//        cout << endl;
//    }
    ll ans = 0;
    for ( int i = 39; i >= 0; --i ) {
        if ( keta_one_list[i].size() < k || keta_one_list[i].empty() ) {
            continue;
        }
//        cout << i << endl;
        ans += 1LL<<i;
        int cnt = 0;
        for ( auto tmp_num : keta_one_list[i] ) {
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
