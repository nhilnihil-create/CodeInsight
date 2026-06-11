#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    if ((n + 1) / 2 >= k) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}