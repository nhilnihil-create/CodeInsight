#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, z, w;
    cin >> n >> z >> w;
    vector<int> a(n);
    rep(i, n)cin >> a[i];
    if(n == 1)cout << abs(a[0]-w) << endl;
    else cout << max(abs(a[n-1]-w), abs(a[n-1]-a[n-2])) << endl;
}