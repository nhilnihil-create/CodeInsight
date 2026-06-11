#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b);
#define chmin(a, b) a = min(a, b);
using namespace std;
using ll = long long;
using P = pair<int,int>;

template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1) {}
  void add(int i, T x=1) {
    for (i++; i <= n; i += i&-i) {
      d[i] += x;
    }
  }
  T sum(int i) {
    T x = 0;
    for (i++; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
  T sum(int l, int r) {
    return sum(r-1) - sum(l-1);
  }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) {
        int t;
        cin >> t;
        a[i] = b[i] = t;
    }
    sort(b.begin(), b.end());
    int l = -1, r = n - 1;
    while(r - l > 1) {
        int c = (l + r) / 2;
        int m = b[c];
        ll cnt = 0;
        BIT<ll> d(3 * n + 5);
        int s = 0;
        rep(i, n + 1) {
            int t = i - 2 * s + 2 * n;
            cnt += d.sum(t - 1);
            d.add(t);
            if (i < n) s += a[i] > m;
        }
        ll len = (ll)n * (n + 1) / 2;
        if (len - cnt < (len + 1) / 2) {
            r = c;
        } else {
            l = c;
        }
    }
    cout << b[r] << endl;
}