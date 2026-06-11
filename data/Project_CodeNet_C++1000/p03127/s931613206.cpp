#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf (1 << 21)
#define mod 1000000007

int gcd(int n, int m) {
    if (n < m) swap(n, m);
    if (n % m == 0) return m;
    return gcd(m, n % m);
}

int main() {
    int N; cin >> N;
    vector<int> A(N);
    int ans;
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
        if (i == 0) ans = A.at(i);
        else ans = gcd(ans, A.at(i));
    }
    cout << ans << endl;
    return 0;
}