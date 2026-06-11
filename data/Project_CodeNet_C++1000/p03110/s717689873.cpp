#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int N;
    cin >> N;
    vector<pair<ld,string>> V(N);
    rep(i,N) {
        cin >> V[i].first >> V[i].second;
    }
    ld ans = 0;
    rep(j,N) {
        if (V[j].second == "BTC") {
            ans += V[j].first*380000.0;
        }
        else {
            ans += V[j].first;
        }
    }
    cout << fixed << setprecision(10);
    cout << ans << endl;
}
