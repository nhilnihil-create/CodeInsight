#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll a, b;
int main() {
    cin >> a >> b;

    int diff = b - a;
    ll total = 0;
    for (int x = 1; x <= diff; x++) {
        total += x;
    }
    cout << total - b << endl;
}