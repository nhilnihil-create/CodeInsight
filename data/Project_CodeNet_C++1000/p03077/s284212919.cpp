#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf (1 << 21)
#define mod 1000000007

int main() {
    ll N, A, B, C, D, E; cin >> N >> A >> B >> C >> D >> E;
    ll minpart1 = min(A, B), minpart2 = min(C, D), minpart3 = min(minpart1, minpart2), m = min(E, minpart3);
    ll n = (N + m - 1) / m;
    ll ans = n + 4;
    cout << ans << endl;
}
