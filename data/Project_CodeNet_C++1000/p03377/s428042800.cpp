#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int A,B,X;
    cin >> A >> B >> X;
    if((A <= X) && ((A+B) >= X)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
