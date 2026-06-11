#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()


int main() {
    int A, B;
    cin >> A >> B;
    if(B % A == 0) cout << A + B << endl;
    else cout << B - A << endl;
}
