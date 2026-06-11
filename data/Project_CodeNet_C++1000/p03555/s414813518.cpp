#include <bits/stdc++.h>
using namespace std;

int main() {
    char A1,B1,C1;cin >> A1 >> B1 >> C1;
    char A2,B2,C2;cin >> A2 >> B2 >> C2;

    if (A1 == C2 && B1 == B2 && C1 == A2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
