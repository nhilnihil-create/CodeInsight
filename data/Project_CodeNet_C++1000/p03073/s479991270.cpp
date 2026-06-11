#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359;
#define inf (1 << 21);
#define mod 1000000007;

int main() {
    string S; cin >> S;
    char first = S.at(0),second;
    if (first == '0') {
        second = '1';
    }
    else {
        second = '0';
    }
    int ans = 0;
    for (int i = 0; i < S.size(); i++) {
        if (i % 2 == 0) {
            if (S.at(i) != first) {
                ans++;
            }
        }
        else {
            if (S.at(i) != second) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}