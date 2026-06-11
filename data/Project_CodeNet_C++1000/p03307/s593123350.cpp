#include <bits/stdc++.h>

int gcd(int a, int b)
{
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main(void)
{
    using namespace std;
    int n;
    cin >> n;
    cout << lcm(2, n) << endl;
}