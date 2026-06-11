#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;

int main() {
    string N;
    cin >> N;
    int cnt = 0;
    rep(i, 4) if (N[i] == '2') cnt += 1;
    cout << cnt << endl;
    return 0;
}