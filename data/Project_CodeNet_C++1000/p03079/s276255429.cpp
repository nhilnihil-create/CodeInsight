#include <bits/stdc++.h>
using namespace std;
void YesNo(bool x) {
    if (x) cout << "Yes" << endl;
    else cout << "No" << endl;
}
int main() {
  int A, B, C; cin >> A >> B >> C;
  YesNo(A==B && B == C);
}
