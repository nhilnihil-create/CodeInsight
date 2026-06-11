#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N), cnts;
    rep(i, N) {
        char c;
        cin >> c;
        A[i] = c - '0';
    }

    int cnt = 1;
    repd(i, 1, N) {
        if (A[i] == A[i - 1]) cnt++;
        else {
            cnts.emplace_back(cnt);
            cnt = 1;
        }
    }
    cnts.emplace_back(cnt);

    int ans = 0;

    int r = 2 * K + A[0];
    int len = (int)cnts.size();
    rep(i, min(r, len)) {
        ans += cnts[i];
    }

    if (A[0] == 1 && len % 2 == 0) cnts.emplace_back(0);
    if (A[0] == 0 && len % 2) cnts.emplace_back(0);

    len = (int)cnts.size();
    int res = ans;
    for (int i = r; i < len; i += 2) {
        res += cnts[i] + cnts[i + 1] - cnts[i - r] - cnts[i - r + 1];
        if (A[0] == 0 && i - r == 0) {
            res += cnts[i - r + 1];
            r++;
        }
        chmax(ans, res);
    }

    cout << ans << endl;
    return 0;
}