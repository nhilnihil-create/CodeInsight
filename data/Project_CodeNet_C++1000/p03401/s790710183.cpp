#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll inf = 1LL<<60;
const double eps = 1e-9;

typedef pair<ll, ll> P;

int main()
{
    int N, tmp = 0, ans = 0;
    cin >> N;
    vector <int> a(N+2, 0);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        ans += abs(a[i-1] - a[i]);
    }
    ans += abs(a[N] - 0);
    for (int i = 1; i <= N; i++) {
        cout << ans - (abs(a[i] - a[i-1]) + abs(a[i] - a[i+1])) + abs(a[i-1] - a[i+1]) << endl;
    }
    return 0;
}

