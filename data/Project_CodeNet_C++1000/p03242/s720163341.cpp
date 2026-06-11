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
    string n; cin >> n;
    for (int i = 0; i < n.size(); i++) {
        if (n.at(i) == '1') n.at(i) = '9';
        else n.at(i) = '1';
    }
    cout << n << endl;
    return 0;
}