// #define _GLIBCXX_DEBUG // for STL debug (optional)
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
#include <bitset>
using namespace std;
using ll = long long int;
using int64 = long long int;
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int INF = 1LL << 29;
const ll LONGINF = 1LL << 60;
const ll MOD = 1000000007LL;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a%b);
}

void solve() {
    ll A, B, C, D; scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
    if(A < B) {
        puts("No");
        return;
    }

    ll q = A % B, g = gcd(B, D);
    q %= g;
    if(q <= min(C, B-D-1)) {
        puts("No");
        return;
    }
    
    // C < q+kg < B -> No
    // C-q < kg < B-q -> No

    // (C-q)/g < k
    ll mik = (C < q ? 0 : (C-q)%g ? (C-q+g-1)/g : (C-q)/g+1);
    // k < (B-q)/g
    ll mak = ((B-q)%g ? (B-q)/g : (B-q)/g-1);
    if(mak - mik + 1 > 0) {
        puts("No");
    }
    else {
        puts("Yes");
    }
}

int main() {
    int T; scanf("%d", &T);
    while(T--) solve();
}
