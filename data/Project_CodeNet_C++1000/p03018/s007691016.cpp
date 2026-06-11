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
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    string s;
    cin >> s;
    int cnt = 0;
    if ( s.length() < 3 ) {
        cout << 0 << endl;
        return 0;
    }
    vector<ll> cont_a_cnt(s.length()+2, 0);
    vector<ll> cont_bc_cnt(s.length()+2, 0);
    rep(i, s.length()) {
        if ( s[i] == 'A' ) {
            cont_a_cnt[i+1] = cont_a_cnt[i]+1;
        }
        if ( i < 2 ) continue;
        if ( s[i-1] == 'B' && s[i] == 'C' ) {
            cont_bc_cnt[i+1] = cont_bc_cnt[i] = cont_bc_cnt[i-1] + 1;
        }
    }
    ll a_num = 0;
    ll b_num = 0;
    bool a_flg = 0;
    bool b_flg = 0;
    ll ans = 0;
    for ( int i = 1; i <= s.length()+1; ++i ) {
//        cout << i << " " << a_num << " " << b_num << endl;
        if ( cont_a_cnt[i] != 0 ) {
            a_flg = 1;
        }
        else if ( a_flg ) {
            a_num += cont_a_cnt[i-1];
            a_flg = 0;
            b_flg = 1;
        }
        if ( !b_flg ) {
            continue;
        }
        if ( cont_bc_cnt[i] == 0 ) {
            b_num = cont_bc_cnt[i-1];
//            cout << b_num << endl;
            ans += a_num * b_num;
            b_flg = 0;
            if ( cont_a_cnt[i] == 0 ) {
                a_num = 0;
            }
            b_num = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
