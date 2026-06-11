#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")




int main() {

    ll n; cin >> n;
    ll sum = 0;
    ll count = 0;
    ll Min = 10000000000;
    vector<ll> a(n);

    rep(i,n){
        cin >> a[i];
        Min = min(Min,abs(a[i]));
        sum += abs(a[i]);
        if(a[i] < 0) count ++;
    }

    if(count%2 == 0) cout << sum;
    else cout << sum-2*Min;
    return 0;
}
