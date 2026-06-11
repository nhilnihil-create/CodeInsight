#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    ll a, b;
    cin >> a >> b;
    ll ans = 0;
    while(a % 4 != 0){
        ans ^= a;
        a++;
    }
    while(b % 4 != 3 && b % 4 != -1){
        ans ^= b;
        b--;
    }
    cout << ans << endl;
}