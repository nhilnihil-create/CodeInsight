#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <iomanip>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<long double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
#define INF 1LL<<60

int main() {
    int N, K;
    cin >> N >> K;
    vector<ull> a(N);
    REP(i, N) cin >> a[i];

    vector< bitset<60> > b(N*(N+1)/2, bitset<60>());
    ull ans = 0;
    int idx = 0;
    REP(i, N) {
        ull tmp = 0ull;
        FOR(j, i, N-1) {
            tmp += a[j];
            auto bits = bitset<60>(tmp);
            REP(bit, 60) b[idx][bit] = bits[bit];
            idx++;
            // cerr << b[idx-1].to_string() << endl;
        }
    }

    int n = N*(N+1)/2;
    REP(bit, 60) {
        int cnt = 0;
        vector<ull> values;
        REP(i, n) {
            if(b[i][60-1-bit] == 1) {
                cnt++;
                ull tmp = b[i].to_ullong();
                values.push_back(tmp);
            }
        }
        if(cnt >= K) {
            sort(ALL(values));
            reverse(ALL(values));
            ans += (1LL << (60-1-bit));
            // REP(i, cnt) cerr << "values[" << i << "] = " << values[i] << endl;
            vector< bitset<60> > b_next(cnt, bitset<60>());
            REP(i, cnt) b_next[i] = bitset<60>(values[i]);
            b = b_next;
            n = cnt;
        }
    }

    cout << ans << endl;

    return 0;
}