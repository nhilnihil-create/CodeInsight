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
#define rALL(a)  (a).rbegin(),(a).rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int MOD = 1000000007;
const double PI = acos(-1); //3.14~
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

using data = pair<ll, vector<ll>>;

int main()
{
    ll x, y, z, k; cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    rep(i, x) cin >> a[i];
    rep(i, y) cin >> b[i];
    rep(i, z) cin >> c[i];
    sort(rALL(a)), sort(rALL(b)), sort(rALL(c));

    priority_queue<data> q;
    set<data> se;
    q.push(data(a[0] + b[0] + c[0], vector<ll>({0, 0, 0})));
    while(k > 0)
    {
        auto cur = q.top(); q.pop();
        cout << cur.first << endl;
        ll ia = cur.second[0], ib = cur.second[1], ic = cur.second[2];

        data tmp;
        if (ia + 1 < a.size())
        {
            tmp = data(a[ia + 1] + b[ib] + c[ic], vector<ll>({ia + 1, ib, ic}));
            if (!se.count(tmp))
            {
                se.insert(tmp);
                q.push(tmp);
            }
        }
        if (ib + 1 < b.size())
        {
            tmp = data(a[ia] + b[ib + 1] + c[ic], vector<ll>({ia, ib + 1, ic}));
            if (!se.count(tmp))
            {
                se.insert(tmp);
                q.push(tmp);
            }
        }
        if (ic + 1 < c.size())
        {
            tmp = data(a[ia] + b[ib] + c[ic + 1], vector<ll>({ia, ib, ic + 1}));
            if (!se.count(tmp))
            {
                se.insert(tmp);
                q.push(tmp);
            }
        }
        k--;
    }
}