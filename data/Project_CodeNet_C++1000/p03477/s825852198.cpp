#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    if (A+B>C+D) cout << "Left\n";
    else if (A+B<C+D) cout << "Right\n";
    else cout << "Balanced\n";
}