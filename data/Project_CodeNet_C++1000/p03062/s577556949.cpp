#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long

const int MOD =  1000000007;
const int IINF = INT_MAX;
const ll INF = 1LL << 60;


int main() {
    int n; cin >> n;
    int cnt = 0;
    ll sum = 0;
    ll mi = INF;
    for(int i = 0; i < n; i++){
        ll a; cin >> a;
        mi = min(abs(a), mi);
        sum += abs(a);
        if(a < 0) cnt++;
    }

    if(cnt & 1) cout << sum - mi * 2 << endl;
    else cout << sum << endl;

    return 0;
}
