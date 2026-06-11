#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    int X;
    cin >> X;
    int ans = 1;
    for(int i = 2; i < 32; i++) {
        int tmp = i;
        while(tmp * i <= X) {
            tmp *= i;
            ans = max(ans, tmp);
        }
    }
    cout << ans;
    return 0;
}
