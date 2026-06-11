#include <bits/stdc++.h>
using namespace std;

int main() {
    int X, H = 0;
    cin >> X;
    int tmp = X;
    string res = "No";

    while (X /= 10 != 0)
    {
        H += X % 10;
        X /= 10;
    }
    
    if (tmp % H == 0) res = "Yes";

    cout << res << endl;
}