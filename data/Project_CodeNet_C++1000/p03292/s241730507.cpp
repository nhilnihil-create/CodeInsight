#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()


int main() {
    int A1, A2, A3;
    cin >> A1 >> A2 >> A3;
    vector<int> A = {A1, A2, A3};
    sort(all(A));
    cout << A[2] - A[0] << endl;
}
