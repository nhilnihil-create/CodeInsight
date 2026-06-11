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
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<vector<int>> sum(N + 1, vector<int>(N + 1, 0));

    rep(i, M) {
        int p, q;
        cin >> p >> q;
        sum[p][q]++;
    }

    rep(i, N) {
        rep(j, N) {
            sum[i + 1][j + 1] += sum[i][j + 1] + sum[i + 1][j] - sum[i][j];
        }
    }

    rep(i, Q) {
        int p, q;
        cin >> p >> q;
        cout << sum[q][q] - sum[p - 1][q] - sum[q][p - 1] + sum[p - 1][p - 1] << endl;
    }
    return 0;
}