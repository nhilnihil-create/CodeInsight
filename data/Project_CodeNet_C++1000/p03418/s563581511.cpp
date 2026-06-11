#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<queue>
#include<deque>
#include<map>
#include<bitset>

#define rep(i, n) for(int i = 0;i < (n);i++)
#define repr(i, n) for(int i = (n);i >= 0;i--)
#define repf(i, m, n) for(int i = (m);i < (n);i++)

using namespace std;
using ll = long long;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};


//////////////////////////////////////////////////



int main() {
    ll n; cin >> n;
    ll k; cin >> k;

    if (k == 0) {
        cout << n*n << endl;
        return 0;
    }

    ll ans = 0;
    for (ll i = k+1; i <= n; i++)
    {
        // cout << "-------------" << endl;
        ans += (n/i)*(i-k);
        // cout << ans << endl;
        if (n%i != 0) ans += max(0ll, n-(n/i)*i-(k-1));
        // cout << ans << endl;
    }
    
    cout << ans << endl;
    
    return 0;
}