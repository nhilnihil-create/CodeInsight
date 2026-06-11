#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int ans = (n + 1) / 2;
    //cout << ans << " " << k << endl;
    if (ans >= k)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}