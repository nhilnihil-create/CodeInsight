#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)(x.size())

using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const ll MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;

template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}

template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}

void fix(vector<P> &num) {
  if(SZ(num) < 2) return;
  if(num[SZ(num)-1].first == num[SZ(num)-2].first) {
    num[SZ(num)-2].second += num[SZ(num)-1].second;
    num.pop_back();
  }
  return;
}

void incr(vector<P> &num) {
  if(num.back().second == 1) {
    num.back().first += 1;
  } else {
    num.back().second--;
    num.push_back(P(num.back().first + 1, 1));
  }
  fix(num);
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n; cin >> n;
  vi a(n);
  for(int i=0;i<n;++i) {
    cin >> a[i];
  }

  int l = 0, r = n+1;
  while(r - l > 1) {
    int mid = (l + r) / 2;
    vector<P> num;
    num.push_back({0, a[0]});
    bool ok = true;
    for(int i=1;i<n;++i) {
      if(a[i-1] < a[i]) {
        num.push_back({0, a[i] - a[i-1]});
      } else {
        int su = 0;
        while(SZ(num) > 0 && su + num.back().second <= a[i-1] - a[i]) {
          su += num.back().second;
          num.pop_back();
        }
        num.back().second -= a[i-1] - a[i] - su;

        if(num.back().first == mid-1) {
          if(SZ(num) == 1) {
            ok = false;
            break;
          }
          int val = num.back().second;
          num.pop_back();
          incr(num);
          num.push_back({0, val});
        } else {
          incr(num);
        }
      }
      fix(num);
    }

    if(ok) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << r << endl;

}
