#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf (1 << 21)
#define mod 1000000007

int main() {
    string S; cin >> S;
    int ans = inf;
    for (int i = 0; i < S.size() - 2; i++) {
        string s;
        for (int j = i; j < i + 3; j++) {
            s += S.at(j);
        }
        int x = stoi(s);
        x = abs(753 - x);
        ans = min(x, ans);
    }
    cout << ans << endl;
    return 0;
}
