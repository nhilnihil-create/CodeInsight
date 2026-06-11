#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main() {
    ll n, k;
    cin >> n >> k;
    ll a = 1;
    rep(i, 0, n) {
        if(2 * a < a + k) a *= 2;
        else a += k;
    }
    cout << a << endl;
    return 0;
}