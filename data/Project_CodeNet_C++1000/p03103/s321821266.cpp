#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf (1 << 21)
#define mod 1000000007

int main() {
    ll N, M; cin >> N >> M;
    vector<pair<ll,ll>> ab(N);
    for (int i = 0; i < N; i++) {
        cin >> ab.at(i).first >> ab.at(i).second;
    }
    sort(ab.begin(),ab.end());
    ll cnt = M;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (cnt > ab.at(i).second) {
            cnt -= ab.at(i).second;
            ans += ab.at(i).first * ab.at(i).second;
        }
        else {
            ans += cnt * ab.at(i).first;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}