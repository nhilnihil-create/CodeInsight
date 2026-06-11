#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {
    ll a, b;
    cin >> a >> b;
    ll res = a - 1;
    if (a <= b) ++res;
    cout << res << endl;
}
