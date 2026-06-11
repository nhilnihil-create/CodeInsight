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
    int N; cin >> N;
    vector<int> a(N);
    int ans = 0, cnt;
    for (int i = 0; i < N; i++) {
        cnt = 0;
        cin >> a.at(i);
        while (a.at(i) % 2 == 0) {
            cnt++;
            a.at(i) /= 2;
        }
        ans += cnt;
    }
    cout << ans << endl;
    return 0;
}