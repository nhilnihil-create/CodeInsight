#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, k;
    cin >> a >> b >> k;

    int c = a + k - 1, d = b - k + 1;

    if (c >= d || c >= b || d <= a)
        for (int i = a; i <= b; i++)
            cout << i << endl;
    else {
        for (int i = a; i <= c; i++)
            cout << i << endl;
        for (int i = d; i <= b; i++)
            cout << i << endl;
    }
}