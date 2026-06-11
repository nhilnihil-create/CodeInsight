#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    int one = 0, two = 0, three = 0;
    rep(i, N) {
        int P;
        cin >> P;
        if (P <= A) one += 1;
        else if (P >= B + 1) three += 1;
        else two += 1;
    }
    cout << min({one, two, three}) << endl;
    return 0;
}