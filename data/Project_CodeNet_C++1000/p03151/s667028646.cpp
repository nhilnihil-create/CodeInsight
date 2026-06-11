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
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n;
    cin >> n;

    vector<ll> a(n);
    ll suma = 0;

    rep(i, n) {
        cin >> a[i];
        suma += a[i];
    }

    vector<ll> b_sub_a(n);
    ll sumb = 0;

    rep(i, n) {
        ll b;
        cin >> b;
        sumb += b;
        b_sub_a[i] = b - a[i];
    }

    if ( sumb > suma ) {
        cout << -1 << endl;
        return 0;
    }

    ll ans = 0;
    ll rest = suma - sumb;
    vector<ll> a_larger_than_b;

    rep(i, n) {
        if ( b_sub_a[i] == 0 ) continue;
        else if ( b_sub_a[i] > 0 ) {
            ++ans;
        }
        else {
            a_larger_than_b.push_back(abs(b_sub_a[i]));
        }
    }

//    cout << rest << " " << a_larger_than_b[0] << endl;

    sort(a_larger_than_b.begin(), a_larger_than_b.end());

    for ( auto tmp_num : a_larger_than_b ) {
        if ( rest >= tmp_num ) {
            rest -= tmp_num;
        }
        else {
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}