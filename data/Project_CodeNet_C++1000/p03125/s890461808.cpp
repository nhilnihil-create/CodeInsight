#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    ll A, B; cin >> A >> B;
    if (B % A == 0) cout << A + B << endl;
    else cout << B - A << endl;
}