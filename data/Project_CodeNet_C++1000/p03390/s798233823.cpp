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
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define int long long int
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
typedef pair<int, int> pii;
typedef long long ll;
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const ll INF = 1001001001001001LL;
const ll MOD = 1000000007LL;
 
signed main() {
    int Q; cin >> Q;
    rep(z,0,Q) {
        int A, B; cin >> A >> B;
        if(A > B) swap(A, B);
        int X = A * B;

        if(A == B) cout << 2*A - 2 << endl;
        else if(A+1 == B) cout << 2*A - 2 << endl;
        else {
            int lb = 0, ub = 1000LL * 1000LL * 1000LL + 100;
            while(ub - lb > 1) {
                int mid = (ub + lb) / 2;
                if(mid * mid < X) {
                    lb = mid;
                }
                else {
                    ub = mid;
                }
            }

            int C = lb;
            if(C*(C+1) >= X) {
                cout << 2*C - 2 << endl;
            }
            else {
                cout << 2*C - 1 << endl;
            }
        }
    }
    return 0;
}