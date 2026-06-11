#pragma region noncode
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1'010'000'000'000'000'017LL;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#pragma endregion

int main() {
    ll a, b;
    cin >> a >> b;
    if(a == b)
        cout << a + b << endl;
    else
        cout << max(a, b) * 2 - 1 << endl;
}
