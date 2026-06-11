#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf (1 << 21)
#define mod 1000000007

int main() {
    double N, T, A; cin >> N >> T >> A;
    vector<double> H(N);
    double moderate = inf;
    int ans;
    for (int i = 0; i < N; i++) {
        cin >> H.at(i);
        moderate = min(moderate, (double)abs(A - T + H.at(i) * 0.006));
        if ((double)abs(A - T + H.at(i) * 0.006) == moderate) {
            ans = i;
        }
    }
    ans++;
    cout << ans << endl;
    return 0;
}