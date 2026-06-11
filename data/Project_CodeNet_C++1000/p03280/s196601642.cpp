#include <bits/stdc++.h>
using namespace std;

int main () {
    int A,B;
    cin >> A >> B;
    int res = A*B;
    int road = A + B - 1;
    cout << res - road << endl;
    return 0;
}