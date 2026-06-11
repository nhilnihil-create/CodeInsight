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
    string S; cin >> S;
    string ans = "AC";
    if (S.at(0) != 'A') {
        ans = "WA";
    }
    int cnt = 0;
    for (int i = 2; i < S.size() - 1; i++) {
        if (S.at(i) == 'C') {
            cnt++;
        }
    }
    if (cnt != 1) {
        ans = "WA";
    }
    for (int i = 0; i < S.size(); i++) {
        if (S.at(i) != 'A' && S.at(i) != 'C') {
            if (S.at(i) <= 'Z') {
                ans = "WA";
            }
        }
    }
    cout << ans << endl;
    return 0;
}