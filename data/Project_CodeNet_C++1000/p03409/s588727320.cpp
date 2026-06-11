#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<P> RED;
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        RED.push_back({-b, a});
    }
    sort(RED.begin(), RED.end());
    rep(i, n) {
        RED[i].first *= -1;
    }
    vector<P> BULE;
    rep(i, n) {
        int c, d;
        cin >> c >> d;
        BULE.push_back({c, d});
    }
    sort(BULE.begin(), BULE.end());
    vector<bool> check(n, false);

    int ans = 0;
    rep(i, n) {
        rep(j, n) {
            if (check[j]) continue;
            if (BULE[i].first > RED[j].second && BULE[i].second > RED[j].first) {
                check[j] = true;
                ans++; 
                break;
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}