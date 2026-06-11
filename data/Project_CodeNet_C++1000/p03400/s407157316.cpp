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
    int N, D, X; cin >> N >> D >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    int ans = X, day;
    for (int i = 0; i < N; i++) {
        day = 1;
        while (day <= D) {
            ans ++;
            day += A.at(i);
        }
    }
    cout << ans << endl;
    return 0;
}