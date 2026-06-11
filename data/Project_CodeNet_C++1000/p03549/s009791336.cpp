#include <iostream>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)

int main() {
    int n, m;
    cin >> n >> m;
    int ans = (n-m)*100 + m*1900;
    rep(i, m) ans *= 2;
    cout << ans << endl;
}