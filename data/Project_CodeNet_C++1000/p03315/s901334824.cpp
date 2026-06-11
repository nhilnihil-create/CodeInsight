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
    string S; cin >> S;
    int ans = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S.at(i) == '+') ans++;
        else ans--;
    }
    cout << ans << endl;
    return 0;
}