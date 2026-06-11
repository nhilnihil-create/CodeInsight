#include <bits/stdc++.h>
using namespace std;
int sumdigit(int n) {
    int s = 0;
    while (n != 0)
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}
int main() {
    int n, a, b, s = 0;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
        if (sumdigit(i) >= a && sumdigit(i) <= b) s += i;
    cout << s;
}