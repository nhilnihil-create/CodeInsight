#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;

int main() {
    ll count = 0;

    ll N;
    cin >> N;
    vector<ll>D(N);

    rep(i, N) {
        cin >> D[i];
    }

    sort(D.begin(), D.end());

    ll M;
    cin >> M;
    vector<ll>T(M);

    rep(i, M) {
        cin >> T[i];
    }

    sort(T.begin(), T.end());

    int i = 0, j = 0;
    
    while (i != N && count != M) {
        if (T[j] == D[i]) {
            count++;
            i++;
            j++;
        }
        else {
            i++;
        }
    }

    if (count == M) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}
