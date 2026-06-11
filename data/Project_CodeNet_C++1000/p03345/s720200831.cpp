#include <bits/stdc++.h>
using namespace std;

int main() {
    long A, B, C, K;
    cin >> A >> B >> C >> K;
    if (abs(A - B) > 1e18) return cout << "Unfair" << endl, 0;
    cout << ((K % 2) ? -(A - B) : A - B) << endl;
}
