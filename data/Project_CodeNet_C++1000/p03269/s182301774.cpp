#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#ifndef LOCAL
#define debug(x) ;
#else
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << '{';
  for (const T &item : v) out << item << ", ";
  out << "\b\b}";
  return out;
}
#endif

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 200010


int main(){
  int L;

  cin >> L;
  L--;

  vector<pair<pair<int,int>,int> > ans;

  bool f = false;
  int sum = 0;
  for(int i=0;i<20;i++){
    int q = 19 - i;
    bool p = (L >> q) & 1;

    debug(f);

    if (p && i)
      ans.push_back({{1, i+1}, sum});
    sum += p << q;

    if (f) {
      ans.push_back({{i, i+1}, 1<<q});
      ans.push_back({{i, i+1}, 0});
    }

    f |= p;
  }

  ans.push_back({{1, 20}, sum});

  cout << 20 << " " << ans.size() << endl;

  for (auto e : ans) {
    cout << e.first.first << " " << e.first.second << " " << e.second << endl;
  }


  return 0;
}
