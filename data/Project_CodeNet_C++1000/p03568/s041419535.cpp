#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    int odd = 0, even = 0;
    rep(i, N) {
        int tmp;
        cin >> tmp;
        tmp % 2 == 1 ? odd += 1 : even += 1;
    }
    cout << pow(3, N) - pow(2, even) << endl;
    return 0;
}