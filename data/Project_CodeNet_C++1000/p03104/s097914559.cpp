#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i > (b); i--)
#define ALL(a) (a).begin(), (a).end()

ll xor_sum(ll num) {
    long long ret;
    if ( num%2 == 0 ) {
        ret = ( (num/2)%2 == 0 ) ? 0 : 1;
        ret ^= num;
    } else {
        ret = ( ((num+1)/2)%2 == 0 ) ? 0 : 1;
    }
    return ret;
}

int main() {
    ll A, B;
    cin >> A >> B;
    cout << (xor_sum(A - 1) ^ xor_sum(B)) << endl;
    return 0;
}