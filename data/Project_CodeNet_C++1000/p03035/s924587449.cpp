#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int A,B;

    cin >> A >> B;
    if(A <= 12) B /=2;
    if(A < 6 ) B = 0;
    cout << B << "\n";
    return 0;
}
