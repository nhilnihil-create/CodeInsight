#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1e18;
#define Pint pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rnr(i,a,b) for(int i=int(a);i>=int(b);i--)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int N; cin >> N;
    vector<int> a(N); rep(i, N) cin >> a[i];
    int maxv = -INF, maxv_i, minv = INF, minv_i;
    rep(i, N) {
        if(maxv < a[i]) {
            maxv = a[i];
            maxv_i = i + 1;
        }
        if(minv > a[i]) {
            minv = a[i];
            minv_i = i + 1;
        }
    }
    if((maxv >= 0 && minv >= 0) || (maxv <= 0 && minv <= 0)) {
        cout << N - 1 << endl;
        if(0 <= minv) {
            rep(i, N - 1) {
                cout << i + 1 << ' ' << i + 2 << endl;
            }
        }else {
            rnr(i, N - 1, 1) {
                cout << i + 1 << ' ' << i << endl;
            }
        }
    } else {
        cout << 2 * N - 1 << endl;
        if(abs(maxv) >= abs(minv)) {
            rep(i, N) {
                cout << maxv_i << ' ' << i + 1 << endl;
            }
            rep(i, N - 1) {
                cout << i + 1 << ' ' << i + 2 << endl;
            }
        }else {
            rep(i, N) {
                cout << minv_i << ' ' << i + 1 << endl;
            }
            rnr(i, N - 1, 1) {
                cout << i + 1 << ' ' << i << endl;
            }
        }
    }
}
