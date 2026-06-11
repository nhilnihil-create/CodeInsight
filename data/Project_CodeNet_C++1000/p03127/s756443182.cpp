#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
const int INF = 1e9;
typedef long long ll;
typedef pair<ll, ll> P;

int main() {
    int N,a[100000];
    cin >> N;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        ans = __gcd(ans, a[i]);
    }
    cout << ans << endl;
    return 0;
}