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
#include <bitset>
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
 
int A[200010], B[200010];
signed main() {
    int N; cin >> N;

    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<N; i++) cin >> B[i];

    int ans = 0;
    for(int d=0; d<29; d++) {
        vector<int> mods;
        for(int i=0; i<N; i++) {
            mods.push_back(B[i] % (1LL << (d+1)));
        }
        sort(mods.begin(), mods.end());

        for(int i=0; i<N; i++) {
            // [lb, ub] の範囲でビットが立つ
            int lb, ub;
            if(A[i] >> d & 1) {
                int mask = A[i] % (1LL << d);
                lb = (1LL << (d+1)) - mask;
                ub = lb + (1LL << d) - 1;
            }
            else {
                int mo = A[i] % (1LL << (d+1));
                lb = (1LL << d) - mo;
                ub = lb + (1LL << d) - 1;
            }

            int div = (1LL << (d+1));
            vector< pair<int, int> > segs;
            if(lb / div != ub / div) {
                segs.push_back(make_pair(lb%div, div-1));
                segs.push_back(make_pair(0, ub%div));
            }
            else {
                segs.push_back(make_pair(lb%div, ub%div));
            }

            /*
            fprintf(stderr, "bit = %s, d = %lld, lb = %lld, ub = %lld\n", bitset<28>(A[i]).to_string().c_str(), d, lb, ub);  
            for(auto x : segs) {
                fprintf(stderr, "[%lld, %lld]\n", x.first, x.second);
            }
            */

            int cnt = 0;
            for(auto x : segs) {
                int L, R; tie(L, R) = x;
                auto idx = lower_bound(mods.begin(), mods.end(), L);
                auto jdx = upper_bound(mods.begin(), mods.end(), R);
                (cnt += (jdx - idx)) %= 2;
            }
            ans ^= (cnt << d);
        }
    }
    cout << ans << endl;
    return 0;
}