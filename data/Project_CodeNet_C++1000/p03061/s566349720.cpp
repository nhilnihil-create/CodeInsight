#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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

int GCD(int a, int b)
{
    return b ? GCD(b, a%b) : a;
}

void PrintVector(const vector<int> &vec)
{
    for (auto val : vec)
        cout << val << " ";
    cout << endl;
}

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }

    vector<int> left(n + 1, 0), right(n + 1, 0);
    rep(i, n) left[i + 1] = GCD(left[i], a[i]);
    RRep(i, n - 1, -1) right[i] = GCD(right[i + 1], a[i]);

    int ans = 0;
    //PrintVector(left);
    //rep(i, right.size()) cout << i << " " << right[i] << endl;
    rep(i, n)
    {
        int l = left[i];
        int r = right[i + 1];

        chmax(ans, GCD(l, r));
    }
    cout << ans << endl;
}