#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << min({a + c, a + d, b + c, b + d}) << endl;
}
