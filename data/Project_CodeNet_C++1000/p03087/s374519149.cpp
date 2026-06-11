#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

typedef long long llong;
typedef unsigned long long ullong;
// -2.1e-9 <= int <= 2.1e9
// -9.2e-18 <= long long <= 9.2e18
// 0 <= unsigned int <= 4.2e9
// 0 <= unsigned long long <= 18.4e18
// cout << fixed << setprecision(10);

int main() {
    uint N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    vector<int> Sum(N+1, 0);
    bool afterA = false;
    int match = 0;

    for (uint i=0; i<N; i++) {

        if (S[i] == 'A') {
            afterA = true;
        }
        else if ((S[i] == 'C') && (afterA)) {
            ++match;
            afterA = false;
        }
        else {
            afterA = false;
        }
        Sum[i+1] = match;
    }

    for (uint q=0; q<Q; q++) {

        uint l, r;
        cin >> l >> r;

        --l;
        --r;
        if ((l >= 1) && (S[l-1] == 'A') && (S[l] == 'C'))
            ++l;
        int ans = Sum[r+1] - Sum[l];
//        if ((l >= 1)
//            && (S[l-1] == 'A') && (S[l] == 'C')) {
//            ans -= 1;
//        }
        cout << ans << endl;
    }
}
