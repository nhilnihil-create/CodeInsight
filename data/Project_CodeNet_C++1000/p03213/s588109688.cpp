#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

class Prime {
  ll _size;
  vector<ll> _min;

 public:
  Prime(ll size) {
    _size = size;
    _min.resize(size);

    for (ll i = 2; i < _size; i++) {
      ll cur = i * 2;
      for (;;) {
        if (cur >= _size) {
          break;
        }
        if (_min[cur] != 0) {
          cur += i;
          continue;
        }
        _min[cur] = i;
      }
    }
  }

  void show() {
    for (ll i = 0; i <= 36; i++) {
      cout << i << ":" << _min[i] << endl;
    }
  }

  vector<ll> v(ll num) {
    vector<ll> result;
    for (;;) {
      ll v = _min[num];
      if (v == 0) {
        result.emplace_back(num);
        break;
      }
      num /= v;
      result.emplace_back(v);
    }
    return result;
  }

  map<ll, ll> m(ll num) {
    map<ll, ll> result;
    for (;;) {
      ll v = _min[num];
      if (v == 0) {
        result[num] += 1;
        break;
      }
      num /= v;
      result[v] += 1;
    }
    return result;
  }
};

void calc_cmul(map<ll, ll> &cmul, map<ll, ll> &primes) {
  for (auto e : primes) {
    ll num = e.first;
    ll count = e.second;

    if (cmul[num] < count) {
      cmul[num] = count;
    }
  }
}

ll c(ll a, ll b) {
  ll r = 1;
  for (ll i = 0; i < b; i++) {
    r *= (a - i);
  }
  for (ll i = 0; i < b; i++) {
    r /= (b - i);
  }
  return r;
}

int main() {
  // std::cout << std::fixed << std::setprecision(10);
  ll N;
  scanf("%lld", &N);

  mll m;
  Prime prime(105);

  for (ll i = 1; i <= N; i++) {
    auto nums = prime.v(i);
    for (ll i = 0; i < nums.size(); i++) {
      ll n = nums[i];
      m[n]++;
    }
  }

  // ll count2 = 0;
  // ll count4 = 0;
  // ll count14 = 0;
  // ll count24 = 0;
  // ll count74 = 0;

  ll count2a = 0;
  ll count4a = 0;
  ll count14a = 0;
  ll count24a = 0;
  ll count74a = 0;

  auto ite = m.begin();
  for (; ite != end(m); ite++) {
    ll key = (*ite).first;
    ll val = (*ite).second;
    // cout << key << ":" << val << endl;
    // if (val >= 74) {
    //   count74++;
    // } else if (val >= 24) {
    //   count24++;
    // } else if (val >= 14) {
    //   count14++;
    // } else if (val >= 4) {
    //   count4++;
    // } else if (val >= 2) {
    //   count2++;
    // }

    if (val >= 2) {
      count2a++;
    }
    if (val >= 4) {
      count4a++;
    }
    if (val >= 14) {
      count14a++;
    }
    if (val >= 24) {
      count24a++;
    }
    if (val >= 74) {
      count74a++;
    }
  }

  // cout << "------------" << endl;

  // cout << "count2:" << count2 << endl;
  // cout << "count4:" << count4 << endl;
  // cout << "count14:" << count14 << endl;
  // cout << "count24:" << count24 << endl;
  // cout << "count74:" << count74 << endl;

  // cout << "------------" << endl;

  // cout << "count2a:" << count2a << endl;
  // cout << "count4a:" << count4a << endl;
  // cout << "count14a:" << count14a << endl;
  // cout << "count24a:" << count24a << endl;
  // cout << "count74a:" << count74a << endl;

  // cout << (c(count4, 3)) << endl;
  // cout << (c(count4, 2) * count2) << endl;

  // 10 * 9 * 8 / 3 / 2

  // auto x = prime.v(32400);
  // for (ll i = 0; i < x.size(); i++) {
  //   cout << x[i] << endl;
  // }

  ll a = 0;

  a += count4a * (count4a - 1) / 2 * (count2a - 2);
  a += count24a * (count2a - 1);
  a += count14a * (count4a - 1);
  a += count74a;

  // cout << (9 * 8 / 2 * 13) << endl;
  // cout << (3 * 14) << endl;
  // cout << (4 * 8) << endl;
  // cout << (1) << endl;

  cout << a << endl;
}

// 32400 -> 2,2,2,2,3,3,3,3,5,5 (10)
//          75個
//          5 * 5 * 3 (4-4-2) 9 * 8/2 * 15
//          25 * 3 (24-2)     3 * 14
//          15 * 5 (14-4)     4 * 8
//          75 (74)           1

// 6 -> 2,3 (3)
//      4個
//      2*2
