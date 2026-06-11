#include <bits/stdc++.h>

using namespace std;

#define sqr(x) ((x) * (x))
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define fin(name) FILE* aasckmasl=freopen(name, "r", stdin)
#define fout(name) freopen(name, "w", stdout)
#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i < r; ++i)
#define E(i, l, r) for(auto i = l; i <= r; ++i)
#define DF(i, l, r) for(auto i = l; i >= r; --i)
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) (x).begin(),(x).end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define sz(a) ((int)(a).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair <int, int> pii;

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const int mod = (int)1e9 + 7;
const dbl eps = (dbl)1e-8;
const int maxn = (int)1e5 + 5;
const dbl pi = acos(-1);

int n, k, ans;
string s;
int d[303][303][303];

int main() {
//    fin("t.in");
    sync;
    cin >> s;
    n = sz(s);
    cin >> k;
    clean(d);
    ans = 0;
    E(i, 0, n) {
    	E(j, 0, n) {
    		if (i + j > n)
    			break;
			int x = i, y = n - 1 - j;
    		E(q, 0, k) {
   				ans = max(ans, 2 * d[i][j][q] + (i + j < n));
				if (x >= y)
					cont;
   				if (s[x] == s[y]) {
   					d[i + 1][j + 1][q] = max(d[i + 1][j + 1][q], d[i][j][q] + 1);
   				}
				d[i + 1][j + 1][q + 1] = max(d[i + 1][j + 1][q + 1], d[i][j][q] + 1);
   				d[i + 1][j][q] = max(d[i + 1][j][q], d[i][j][q]);
   				d[i][j + 1][q] = max(d[i][j + 1][q], d[i][j][q]);
    		}
    	}
    }
    cout << ans << endl;
    return 0;
}