#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

// Segment Tree {{{
template <typename T>
class SegTree {
 private:
    int _n;
    T _init_val;
    std::vector<T> _data;
    std::function<T(T, T)> _f;

    T _query(int a, int b, int k, int l, int r) {
        // [a b)と[l r]が交差しない
        if (r <= a || b <= l) return _init_val;

        // [a b)が[l r]を含む
        if (a <= l && r <= b) return _data[k];

        T vl = _query(a, b, k*2+1, l, (l+r)/2);
        T vr = _query(a, b, k*2+2, (l+r)/2, r);

        return _f(vl, vr);
    }

 public:
    SegTree(int n, T init_val, std::function<T(T, T)> f) {
        _init_val = init_val;
        _n = 1;
        _f = f;

        while (_n < n)
            _n *= 2;
        _data.resize(2 * _n, init_val);
    }

    T get(int k) {
        return _data[k + _n - 1];
    }

    void update(int k, T a) {
        k += _n-1;
        _data[k] = a;
        while (k > 0) {
            k = (k-1)/2;
            _data[k] = _f(_data[k*2+1], _data[k*2+2]);
        }
    }

    // [a b)の範囲でfを適用
    T query(int a, int b) {
        return _query(a, b, 0, 0, _n);
    }

    // 先頭からチェックし，はじめてxを満たしたインデックス
    int lower_bound(T x) {
        return _lower_bound(x, 0);
    }

    int _lower_bound(T x, int k) {
        if (k >= _n-1) {
            return k - (_n - 1);  // 葉
        } else if (_data[k] < x) {
            return _n;  // 該当なし
        } else if (x <= _data[k * 2 + 1]) {
            return _lower_bound(x, k * 2 + 1);
        } else {
            return _lower_bound(x - _data[k * 2 + 1] , k * 2 + 2);
        }
    }
};
// }}}

ll f(ll x, ll y){
  return x+y;
}

signed main() {
  ll N, K;
  cin >> N >> K;
  SegTree<ll> st(N, 0, f);
  rep(i,N) {
    ll x;
    cin >> x;
    st.update(i, x);
  }
  vector<ll> v;
  for (ll i=0; i<N; i++) {
    for (ll j=i; j<N; j++) {
      v.push_back(st.query(i, j+1));
    }
  }
  sort(begin(v), end(v));
  //cout << "v: ";
  //for(auto x: v) {
  //  cout << x << " ";
  //}
  //cout << endl;

  vector<ll> can;
  rep(i, v.size())
    can.push_back(i);

  for (ll bit=((ll)1)<<50; bit>0; bit = bit >> 1) {
    vector<ll> t;
    for(auto ix : can) {
      if ((v[ix] & bit) != 0) {
        t.push_back(ix);
      }
    }
    //printf("bit: %08X can: ", bit);
    //for(auto ix : can) {
    //  cout << v[ix] << " ";
    //}
    //printf("t: ");
    //for(auto ix : t) {
    //  cout << v[ix] << " ";
    //}
    //cout << endl;
    if (t.size() == K) {
      can = t;
      break;
    } else if (t.size() > K) {
      can = t;
    } else {
      ; // none
    }
  }

  ll ans = v[can[0]];
  rep(i,K){
    auto ix = can[i];
    ans &= v[ix];
  }
  cout << ans << endl;
  return 0;
}
