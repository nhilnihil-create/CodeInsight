#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 10000000000000000; //10^16
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    ll A, B;
    cin >> A >> B;
    ll ans = 0;
    for (ll i = (A-1)/4 * 4; i < A; i++)
    {
        ans = ans ^ i;
    }
    for (ll i = B/4 * 4; i < B+1; i++) {
        ans = ans ^ i;
    }
    

    printf("%lld\n", ans);

}

