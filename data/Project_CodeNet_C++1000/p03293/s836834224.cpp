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
    string S, T; cin >> S >> T;
    string ans = "Yes";
    int k = 0;
    while (S != T) {
        for (int i = 0; i < S.size() - 1; i++) {
            swap(S.at(i), S.at(i + 1));
        }
        k++;
        if (k == S.size()) {
            ans = "No";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}