#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    ll n, m;
    cin >> n >> m;
    if(n == 1 && m == 1) cout << 1 << endl;
    else if(min(n, m) == 1) cout << max(n, m) - 2 << endl;
    else{
        cout << (n - 2) * (m - 2) << endl;
    }
}