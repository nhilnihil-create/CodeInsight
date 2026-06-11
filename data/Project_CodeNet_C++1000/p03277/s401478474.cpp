#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(int i = 1;i <=  n; i++)
#define rrep(i,n) for(ll i = n-1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
#define RALL(a) rbegin(a),rend(a)
typedef long long int ll;
typedef long double ld;
const ll INF = 1e15;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
const int MAX = 510000;
const int MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int n; vector<int> a;
template <class Abel> struct BIT {
    const Abel UNITY_SUM = 0;                       // to be set
    vector<Abel> dat;
    BIT(int n) : dat(n + 1, UNITY_SUM) { }
    void init(int n) { dat.assign(n + 1, UNITY_SUM); }
    inline void add(int a, Abel x) {
        for (int i = a; i < (int)dat.size(); i += i & -i)
            dat[i] = dat[i] + x;
    }
    inline Abel sum(int a) {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i)
            res = res + dat[i];
        return res;
    }
    inline Abel sum(int a, int b) {
        return sum(b - 1) - sum(a - 1);
    }
};
int main(void) {
    cin >> n;a.resize(n);
    rep(i, n) cin >> a[i];
    int right = 1<<30,left = 0;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        ll cnt = 0;
        BIT<ll> bit(n * 2 + 10);
        int sum = 0;
        bit.add(n + 1, 1);
        rep(i, n) {
            sum += (a[i] <= mid) ? 1 : -1;
            cnt += bit.sum(1, sum + n + 1);
            bit.add(sum + n + 1, 1);
        }if (cnt >(ll)n * (n + 1) / 4)right = mid;
        else left = mid;
    }cout << right << endl;
}