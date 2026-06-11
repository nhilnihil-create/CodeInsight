#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B,C,D,L,R;
    cin >> A >> B >> C >> D;
    L = A + B;
    R = C + D;
    if (L > R) cout << "Left";
    else if (L == R) cout << "Balanced";
    else cout << "Right";
}
