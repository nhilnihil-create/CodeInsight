#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()


int main() {
    int K;
    cin >> K;
    int odd = (K + 1) / 2;
    int even = K / 2;
    cout << odd * even << endl;
}
