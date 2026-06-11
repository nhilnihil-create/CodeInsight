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
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    ll k, a, b;
    cin >> k >> a >> b;
    if ( k < a ) {
        cout << k+1LL << endl;
        return 0;
    }
    if ( a >= b ) {
        cout << k+1LL << endl;
        return 0;
    }
    ll ans = a;
    k -= a-1LL;
    if ( b - a == 1 ) {
        cout << ans + k << endl;
        return 0;
    }
    if ( !(k&1) ) {
        cout << ans + (b-a) * (k/2LL) << endl;
        return 0;
    }
    cout << ans + (b-a) * ((k-1)/2LL) + 1LL << endl; 
    return 0;
}
