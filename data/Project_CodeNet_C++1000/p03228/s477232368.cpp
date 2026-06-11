#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        if (i%2) {
            b += a/2;
            a /= 2;
        }
        else {
            a += b/2;
            b /= 2;
        }
    }
    cout << a << " " << b << "\n";
}
