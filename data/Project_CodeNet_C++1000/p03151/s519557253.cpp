#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <list>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {

    ll N;
    cin >> N;
    vector<ll> A(N), B(N), C(N);

    ll totalA = 0;

    rep(i, N) {
        cin >> A[i];
        totalA += A[i];
    }
    
    ll totalB = 0, count = 0;

    rep(i, N) {
        cin >> B[i];
        totalB += B[i];
        C[i] = A[i] - B[i];
        if (C[i] < 0) {
            count++;
        }
    }

    ll ans = 0;

        if (count == 0) {
        ans = 0;
    }
    else if (totalA < totalB) {
        ans = -1;
    }
    else {
        sort(C.begin(), C.end());
        ll i = 0, j = N - 1, stack = 0;
        while (C[i] < 0) {
            stack += C[i];
            while (stack < 0) {
                stack += C[j];
                j--;
                count++;
            }
            i++;
        }
        ans = count;
    }

    cout << ans;

    return 0;
}
