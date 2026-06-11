#include <bits/stdc++.h>
using namespace std;
int main() {
    long long x, y, k = 0;
    cin >> x >> y;
    for (long long i = x; i <= y;)
    {
        i *= 2;
        k++;
    }
    cout << k;
}