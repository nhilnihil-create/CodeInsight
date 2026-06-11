#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    long long n, m;

    cin >> n >> m;

    long long tmp;
    tmp = 1900 * m + 100 * (n - m);

    cout << (long long)tmp * pow(2,m);
    //
}
