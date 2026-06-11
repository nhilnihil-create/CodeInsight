#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, k, s = 0, p, r;
    cin >> n >> k;
    for (long long b = 1; b <= n; b++) 
    {
        p = n / b;
        r = n % b;
        s += p * max((long long)0, b - k) + max((long long)0, r - k + 1);
    }
    if (k == 0) cout << s - n;
    else cout << s;
}