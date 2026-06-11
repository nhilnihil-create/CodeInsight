#include <bits//stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(obj) begin(obj), end(obj)
typedef long long int ll;
int n; vector<int> a;
template <class Abel> struct BIT {
    const Abel UNITY_SUM = 0; vector<Abel> dat;
    BIT(int n) : dat(n + 1, UNITY_SUM) { }
    void init(int n) { dat.assign(n + 1, UNITY_SUM); }
    inline void add(int a, Abel x) {
        for (int i = a; i < (int)dat.size(); i += i & -i)
            dat[i] = dat[i] + x;
    }
    inline Abel sum(int a) {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i) res = res + dat[i];
        return res;
    }
    inline Abel sum(int a, int b) {
        return sum(b - 1) - sum(a - 1);
    }
};
int main() {
    cin >> n;a.resize(n);
    rep(i, n) cin >> a[i];
    int right = 1<<30,left = 0;// right > 10^10以上で
    while (right - left > 1) {
        int mid = (right + left) / 2,sum = 0;
        ll cnt = 0;BIT<ll> bit(n * 2 + 10);
        bit.add(n + 1, 1);
        rep(i, n) {
            sum += (a[i] <= mid) ? 1 : -1;
            cnt += bit.sum(1, sum + n + 1);
            bit.add(sum + n + 1, 1);
        }if (cnt >(ll)n * (n + 1) / 4)right = mid;
        else left = mid;
    }cout << right << endl;
}