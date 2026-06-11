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
    int N;
    cin >> N;
    map<int, int> D;
    rep(i, N) {
        int d;
        cin >> d;
        if (d <= 12) D[d]++;
        else D[24 - d]++;
    }

    repd(i, 1, 12) {
        if ((D.count(0) != 0 && D[0] >= 1) ||
            (D.count(12) != 0 && D[12] >= 2) ||
            (D.count(i) != 0 && D[i] >= 3)) 
        {
            cout << 0 << endl;
            return 0;
        }
    }
    int ans = 0;
    for (int bit = 0; bit < (1 << 11); bit++) {
        vector<int> t(24, 0);
        t[0] = 1; t[12] = (int)D.count(12);
        rep(i, 11) {
            if (D.count(i + 1) == 0) continue;
            if (bit & (1 << i)) {
                if (D[i + 1] == 2) t[24 - (i + 1)] = 1;
                t[i + 1] = 1;
            }
            else {
                if (D[i + 1] == 2) t[i + 1] = 1;
                t[24 - (i + 1)] = 1;
            }
        }
        int mi = 1e9;
        rep(i, 24) {
            if (t[i] == 0) continue;
            repd(j, i + 1, 24) {
                if (t[j] == 0) continue;
                chmin(mi, min(j - i, 24 - (j - i)));
            }
        }
        chmax(ans, mi);
    }

    cout << ans << endl;
    return 0;
}