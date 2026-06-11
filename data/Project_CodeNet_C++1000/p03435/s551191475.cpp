#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    vector<vector<int>> c(3, vector<int>(3));
    for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) cin >> c[i][j];
    vector<int> a(3), b(3);
    b[0] = 0; a[0] = c[0][0]; b[1] = c[0][1] - c[0][0];
    b[2] = c[0][2] - c[0][0]; a[1] = c[1][0]; a[2] = c[2][0];
    string ans = "Yes";
    for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) {
        int test = a[i] + b[j];
        if(test != c[i][j]) {
            ans = "No";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}