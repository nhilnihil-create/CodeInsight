#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define rrep(i,n) for(int i=int(n-1);i>=0;i--)
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long;
using P = pair<int, int>;
using lP = pair<ll, ll>;
using fP = pair<double, double>;
using PPI = pair<P, int>;
ll const mod = 998244353;
const ll MAX = 300000;
using vi = vector<int>;
using vc = vector<char>;
using vd = vector<double>;
using vs = vector<string>;
using vp = vector<P>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvc = vector<vector<char>>;
using vvp = vector<vector<P>>;
using vvb = vector<vector<bool>>;
template <typename T>
bool chmax(T& a, const T b) { if (a < b) { a = b; return true; } return false; }
template <typename T>
bool chmin(T& a, const T b) { if (a > b) { a = b; return true; } return false; }


//////////////////////////////////////


int main() {
    int n;
    cin >> n;
    vector<PPI> co(2 * n);
    vi alt;
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        co[i].fs.fs = a;
        co[i].fs.sc = b;
        co[i].sc = 1;
        alt.push_back(a);
        alt.push_back(b);
    }
    rep(i, n) {
        int c, d;
        cin >> c >> d;
        co[i + n].fs.fs = c;
        co[i + n].fs.sc = d;
        co[i + n].sc = 0;
        alt.push_back(c);
        alt.push_back(d);
    }
    sort(all(alt));
    alt.erase(unique(all(alt)), alt.end());
    rep(i, n) {
        co[i].fs.fs = lower_bound(all(alt), co[i].fs.fs) - alt.begin();
        co[i].fs.sc = lower_bound(all(alt), co[i].fs.sc) - alt.begin();
        co[i + n].fs.fs = lower_bound(all(alt), co[i+n].fs.fs) - alt.begin();
        co[i + n].fs.sc = lower_bound(all(alt), co[i+n].fs.sc) - alt.begin();

    }
    sort(all(co));
    vi stock(2 * n);
    ll ans = 0;
    rep(i, 2 * n) {
        if (co[i].sc == 1) {
            stock[co[i].fs.sc]++;
        }
        else {
            int tmp = co[i].fs.sc - 1;
            while (tmp >= 0) {
                if (stock[tmp] > 0) {
                    stock[tmp]--;
                    ans++;
                    break;
                }
                tmp--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}