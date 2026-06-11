#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Rep(i, k, n) for (int i = k; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int MOD = 1000000007;
const double PI = acos(-1); //3.14~
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    int n, m; cin >> n >> m;
    P itv[m];
    rep(i, m)
    {
        cin >> itv[i].second >> itv[i].first;
    }

    sort(itv, itv + m);

    int ans = 0, cur = 0;
    rep(i, m)
    {
        if (cur <= itv[i].second)
        {
            //cout << itv[i].second << endl;
            ans++;
            cur = itv[i].first;
        }
    }
    cout << ans << endl;
}