#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
//#define cerr if(false) cerr
#ifdef DEBUG
#define show(...) cerr << #__VA_ARGS__ << " = ", debug(__VA_ARGS__);
#else
#define show(...) 42
#endif
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T, typename S>
ostream& operator<<(ostream& os, pair<T, S> a) {
    os << '(' << a.first << ',' << a.second << ')';
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
    for (auto x : v) os << x << ' ';
    return os;
}
void debug() {
    cerr << '\n';
}
template <typename H, typename... T>
void debug(H a, T... b) {
    cerr << a;
    if (sizeof...(b)) cerr << ", ";
    debug(b...);
}
int main(){
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<int>dp(n+1,1<<30);
    vector<int> h(1 << 26, 1<<30);//ハッシュ値がxとなるものでdpの値の最小値
    h[0] = 0;
    int k = 0;
    rep(i,n){
        k ^= (1 << (s[i] - 'a'));
        rep(j,26){
            int sub = 1 << j;
            int kk = k ^ sub;
            if(h[kk] == 1<<30)continue;
            dp[i + 1] = min(dp[i + 1], h[kk] + 1);
        }
        h[k] = min(h[k], dp[i+1]);
    }
    cout << (k == 0 ? 1 : dp[n]) << endl;
}