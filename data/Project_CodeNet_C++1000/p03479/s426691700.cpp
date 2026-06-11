#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n); ++i)
typedef long long ll;

const int mod = 1e9+7;
const int INF = 2000000;

int main() {
    ll X,Y;
    cin >> X >> Y;
    int ans = 0;
    while(X <= Y) {
        ++ans;
        X *= 2; 
    }
    cout << ans << endl;
}
