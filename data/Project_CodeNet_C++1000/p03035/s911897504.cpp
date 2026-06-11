#include <bits/stdc++.h>
#include <math.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
#define REP(i,n) for (int i = 1; i<= (n); i++)
#define MAX_MOD 1000000007LL
#define MOD 998244353LL
const long double PI = acos(-1);
using ll = long long;
using ld = long double;
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    if (a >= 13) {
        ans = b;
    } else if (a >= 6 && a <= 12) {
        ans = b / 2;
    }
    cout << ans << endl;
    return 0;
}