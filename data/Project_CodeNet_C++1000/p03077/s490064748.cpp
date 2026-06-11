#include <iostream>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)

int main() {
    long long n;
    long long t[5];
    cin >> n;
    long long m = 1e16;
    rep(i, 5) {
        cin >> t[i];
        m = min(m, t[i]);
    }
    long long ans = 4;
    ans += (n+m-1) / m;
    cout << ans << endl;
}