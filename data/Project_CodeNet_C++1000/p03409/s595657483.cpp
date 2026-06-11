#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Rep(i, k, n) for (int i = k; i < (int)(n); i++)
#define RRep(i, k, n) for (int i = k; i > (int)(n); i--)
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define ALL(a)  (a).begin(),(a).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int MOD = 1000000007;
const double PI = acos(-1); //3.14~
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    int n; cin >> n;
    vector<P> red(n), blue(n);
    rep(i, n)
    {
        int a, b; cin >> a >> b;
        red[i] = make_pair(a, b);
    }
    rep(i, n)
    {
        int a, b; cin >> a >> b;
        blue[i] = make_pair(a, b);
    }

    sort(ALL(blue));
    vector<bool> seen(n);

    int ans = 0;
    rep(i, n)
    {
        int tmp = -1, maxy;
        bool f = false;
        rep(j, n)
        {
            if (red[j].first < blue[i].first && red[j].second < blue[i].second &&
            red[j].second > tmp && !seen[j])
            {
                tmp = red[j].second;
                maxy = j;
                f = true;
            }
        }
        if (f)
        {
            seen[maxy] = true;
            ans++;
        }
    }
    cout << ans << endl;
}