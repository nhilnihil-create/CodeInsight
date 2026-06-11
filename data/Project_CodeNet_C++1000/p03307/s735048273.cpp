#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, gcd, lcm;
    cin >> n;
    gcd = __gcd(2ll, n);
    lcm = (n / gcd) * 2;
    cout << lcm << endl;
}