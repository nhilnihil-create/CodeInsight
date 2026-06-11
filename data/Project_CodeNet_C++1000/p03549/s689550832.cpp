#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    cout << ((n-m)*(1<<m)*100 + m*(1<<m)*1900) << '\n';

    return 0;
}
