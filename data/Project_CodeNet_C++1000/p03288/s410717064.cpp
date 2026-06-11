#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int R; cin >> R;
    if (R < 1200) {
        cout << "ABC" << endl;
    }
    else if (R < 2800) {
        cout << "ARC" << endl;
    }
    else {
        cout << "AGC" << endl;
    }
    return 0;
}