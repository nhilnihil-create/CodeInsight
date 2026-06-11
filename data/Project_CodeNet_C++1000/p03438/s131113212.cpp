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
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    ll one_cnt = 0;
    ll two_cnt = 0;
    rep(i, n) {
        ll diff = b[i] - a[i];
        if ( diff < 0 ) one_cnt += -diff;
        if ( diff > 0 ) two_cnt += diff / 2;
    }
    if ( two_cnt >= one_cnt ) cout << "Yes" << endl;
    else                      cout << "No" << endl;
    return 0;
}
