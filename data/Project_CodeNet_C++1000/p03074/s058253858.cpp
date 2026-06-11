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
    string S;
    cin >> N >> K >> S;
    vector<int> color(N);
    REP(i, N) color[i] = S[i] - '0';

    int state = 1, continuous = 0, begin = 0;
    vector<int> white, black, white_begin, white_end;
    // if(color[0] == 0) black.push_back(0);
    REP(i, N) {
        if(state != color[i]) {
            if(state == 0) {
                white.push_back(continuous);
                white_begin.push_back(begin);
                white_end.push_back(i);
            } else {
                black.push_back(continuous);
            }
            state = color[i];
            continuous = 1;
            begin = i + 1;
        } else {
            continuous++;
        }
    }

    if(color[N-1] == 0) {
        white.push_back(continuous);
        black.push_back(0);
    }
    else black.push_back(continuous);


    if(white.size() == 0) {
        cout << black[0] << endl;
        return 0;
    }

    // REP(i, black.size()) {
    //     cerr << "black[" << i << "] = " << black[i] << endl;
    // }
    
    // REP(i, white.size()) {
    //     cerr << "white[" << i << "] = " << white[i] << endl;
    // }

    int ans = 0;
    REP(black_begin, black.size()) {
        int tmp = black[black_begin];
        FOR(white_idx, black_begin, min(black_begin + K, int(white.size())) - 1) {
            tmp += white[white_idx] + black[white_idx+1];
            // cerr << "black_begin = " << black_begin << " tmp = " << tmp << endl;
        }
        if(tmp > ans) ans = tmp;
    }

    cout << ans << endl;

    return 0;
}
