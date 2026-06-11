#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;

    if(n % 2 == 0) {
        cout << n << endl;
        return 0;
    }

    cout << 2 * n << endl;
    return 0;
}
