#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rrep(i, n) for(int i=n-1; i>=0; i--)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    int n; cin >> n;
    vector<pii> red(n), blue(n);
    rep(i, n) cin >> red[i].first >> red[i].second;
    rep(i, n) cin >> blue[i].first >> blue[i].second;
    sort(blue.begin(), blue.end());

    int ans = 0;
    rep(i, n) {
        int maxY = -1, idx = -1;
        rep(j, red.size()) {
            if (red[j].first < blue[i].first && red[j].second < blue[i].second) {
                if (red[j].second > maxY) {
                    maxY = red[j].second;
                    idx = j;
                }
            }
        }
        if (idx >= 0) {
            ans++;
            red.erase(red.begin() + idx);
        }
    }
    cout << ans << endl;
}

