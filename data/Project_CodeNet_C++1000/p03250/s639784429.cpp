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
    vector<string> S(3);
    for (int i = 0; i < 3; i++) {
        cin >> S.at(i);
    }
    sort(S.begin(), S.end());
    string x = S.at(2) + S.at(1), y = S.at(0);
    int ans = stoi(x) + stoi(y);
    cout << ans << endl;
    return 0;
}