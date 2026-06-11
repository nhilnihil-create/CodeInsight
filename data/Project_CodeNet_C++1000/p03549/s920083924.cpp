#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, m; cin >> n >> m;
    int p = pow(2, m);

    cout << ((n-m)*100*p) + (1900*m)*p << endl;
}
