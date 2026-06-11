#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    multiset<int, greater<int>> a;
    int ans = 0;
    vector<int> powers;
    ll p = 1;
    while (p <= (2 * 1e9)) {
        powers.push_back(p);
        p *= 2;
    }
    rep(i, n) {
        int tmp;
        cin >> tmp;
        a.insert(tmp);
    }
    auto it = a.begin();
    while(sz(a)) {
        bool deleted = false;
        rrep(i, sz(powers)) {
            if (powers[i] <= *it) break;
            auto itp = a.find(powers[i] - *it);
            if (itp == it) itp++;
            if (itp == a.end()) continue;
            if (*itp == (powers[i] - *it)) {
                a.erase(itp);
                a.erase(it++);
                ans++;
                deleted = true;
                break;
            }
        }
        if (!deleted) a.erase(it++);
    }
    cout << ans << endl;
    return 0;
}