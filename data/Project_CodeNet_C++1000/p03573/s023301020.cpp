#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if      (A == B) cout << C << endl;
    else if (A == C) cout << B << endl;
    else if (B == C) cout << A << endl;
}