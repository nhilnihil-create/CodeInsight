#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<string> vs;
const long long INF = 1LL << 60;
const int INT_INF = 1 << 30;
const double PI = acos(-1.0);

int main() {
    string s;
    cin >> s;
    int ans = 0;
    rep(i, s.size()) {
        int ret = 0;
        rep2(j, i, s.size()) {
            if (s[j] == 'A' || s[j] == 'C' || s[j] == 'T' || s[j] == 'G')
                ret++;
            else
                break;
        }
        ans = max(ans, ret);
    }
    cout << ans << endl;
}