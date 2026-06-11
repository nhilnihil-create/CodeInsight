#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    cout << (a * b % 2 == 0 ? "Even" : "Odd") << endl;

    return 0;
}
