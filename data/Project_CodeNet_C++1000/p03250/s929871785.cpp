#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()


int main() {
    int A, B, C;
    cin >> A >> B >> C;
    cout << max(10 * A + B + C,max( A + 10 * B + C, A + B + 10 * C)) << endl;
}
