#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, m;
    cin >> n >> m;
    cout << 100 * (18 * m + n) * floor(pow(2, m));
}