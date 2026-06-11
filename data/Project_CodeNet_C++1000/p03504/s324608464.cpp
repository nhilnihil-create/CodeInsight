#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, c;
    cin >> n >> c;
    vector<vector<int>> imos(c, vector<int>(101010, 0));
    for(int i = 0; i < n; i++) {
        int s, t, cc;
        cin >> s >> t >> cc;
        cc--;
        imos[cc][s]++;
        imos[cc][t + 1]--;
    }
    for(int i = 0; i < c; i++) {
        for(int j = 1; j < 101010; j++) {
            imos[i][j] += imos[i][j - 1];
        }
    }
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < 101010; j++) {
            if(imos[i][j] >= 1) {
                imos[i][j] = 1;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 101010; i++) {
        int cnt = 0;
        for(int j = 0; j < c; j++) {
            cnt += imos[j][i];
        }
        chmax(ans, cnt);
    }
    cout << ans << endl;
}