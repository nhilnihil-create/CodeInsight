#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353
#define Graph vector<vector<int>>

int main() {
    vector<int> X(3);
    for (int i = 0; i < 3; i++) cin >> X.at(i);
    sort(X.begin(), X.end());
    int &A = X.at(0), &B = X.at(1), &C = X.at(2);
    int ans = 0;
    while (A != B || B != C || C != A) {
        if (A < C && B < C) {
            A++;
            B++;
            ans++;
        }
        else if (A < C && B >= C) {
            A += 2;
            ans++;
        }
        else if (A >= C && B < C) {
            B += 2;
            ans++;
        }
        sort(X.begin(), X.end());
    }
    cout << ans << endl;
    return 0;
}