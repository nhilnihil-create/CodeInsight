#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    int A, B;
    cin >> A >> B;
    int ans = 0;
    if(A >= 6) ans = B / 2;
    if(A >= 13) ans = B;
    cout << ans;
    return 0;
}
