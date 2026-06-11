#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long int ll;
#define EPS (1e-7)
#define INF (1e9 + 10)
#define PI (acos(-1))
#define MOD (1000000007)
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define ALL(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    int N;
    cin >> N;
    int a[N], b[N];
    REP(i, N) {
        cin >> a[i];
    }
    REP(i, N) {
        cin >> b[i];
    }

    ll ans = 0;
    REP(i, N) {
        ans ^= a[i];
        ans ^= b[i];
    }
    ll temp = 0;
    REP(i, N) {
        temp ^= ans;
    }
    ans = temp;
    int am[N];
    int bm[N];
    REP(d, 29) {
        ll mod = pow(2, d);
        int c = 0;
        REP(i, N) {
            am[i] = a[i] % mod;
            bm[i] = b[i] % mod;
        }
        sort(bm,bm+N);
        REP(i, N) {
            ll key = mod - am[i];
            c ^= (bm+N - lower_bound(bm, bm+N, key))%2;//end - lowerboundで以上の数。
        }
        ans ^= (c << d);
    }
    cout << ans << endl;
}