#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int a, b;

        cin >> a >> b;

        int sum = a + b;
        int sub = a - b;
        int mult = a * b;

        cout << max(max(sum, sub), mult) << endl;
        return 0;
}
