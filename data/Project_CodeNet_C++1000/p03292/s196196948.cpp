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
    vector<int> A(3);
    for (int i = 0; i < 3; i++) {
        cin >> A.at(i);
    }
    sort(A.begin(), A.end());
    int ans = 0;
    ans = min(abs(A.at(0) - A.at(2)) + abs(A.at(0) - A.at(1)), abs(A.at(1) - A.at(2)) + abs(A.at(1) - A.at(0)));
    cout << ans << endl;
    return 0;
}