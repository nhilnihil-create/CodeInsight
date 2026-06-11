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
    int A, B, C, X; cin >> A >> B >> C >> X;
    int ans = 0;
    for(int i = 0; i <= A; i++) for(int j = 0; j <= B; j++) for(int k = 0; k <= C; k++) {
        if(500 * i + 100 * j + 50 * k == X) ans++;
    }
    cout << ans << endl;
    return 0;
}