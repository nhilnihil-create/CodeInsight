// 基本テンプレート

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
using namespace std;

#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)
#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)

template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}

typedef pair<int, int> pii;
typedef long long ll;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
constexpr int INF = 1001001000;
constexpr ll MOD = 1000000007LL;

int bit[200010];
int dp[1 << 26];

// generate binary string (not less than k-digit)
string to_binString(int n, int k) {
    string ret = "";
    while(n) ret += ('0' + (n&1)), n >>= 1;
    while(ret.length() < k) ret += '0';
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    string s; cin >> s;
    int len = s.length();
    rep(i,0,len) {
        bit[i+1] = bit[i];
        bit[i+1] ^= (1 << (s[i] - 'a'));
    }

    fill(dp, dp+(1<<26), INF);
    dp[0] = 0;
    rep(i,0,len) {
        int bt = bit[i+1], opt = INF;
        rep(k,-1,26) {
            int nbit = (k < 0 ? bt : bt ^ (1 << k));
            chmin(opt, dp[nbit] + 1);
        }
        chmin(dp[bt], opt);
        if(i == len-1) cout << max(dp[bt], 1) << endl;
    }
    return 0;
}