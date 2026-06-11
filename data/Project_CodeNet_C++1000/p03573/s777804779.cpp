#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()


int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if(A == B) cout << C << endl;
    if(A == C) cout << B << endl;
    if(B == C) cout << A << endl;
}
