#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define D()
#define INF 1000000000000
#define MOD 10000007
#define MAXR 100000
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define INITA(a,i,j,v) for(ll k=i;k<=j;k++){a[k]=v;}

int main() {
    int n; cin >> n;
    int x_cur = 0;
    int y_cur = 0;
    int t_cur = 0;
    REP(i, n) {
        int t, x, y; cin >> t >> x >> y;
        int abs_diff = abs(x_cur - x) + abs(y_cur - y);
        int t_diff = t - t_cur;

        bool ok = false;

        if (abs_diff == t_diff) {
            ok = true;
        } else if (abs_diff < t_diff) {
            if (abs_diff % 2 == t_diff % 2) {
                ok = true;
            } else {
                ok = false;
            }
        } else {
            ok = false;
        }

        if (ok) {
            x_cur = x;
            y_cur = y;
            t_cur = t;
        } else {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}