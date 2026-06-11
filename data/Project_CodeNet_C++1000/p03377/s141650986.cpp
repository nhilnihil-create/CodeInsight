#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int a, b, x;

        cin >> a >> b >> x;

        if (x  > (a + b) || a > x) {
                cout << "NO" << endl;
        } else {
                cout << "YES" << endl;
        }

        return 0;
}
