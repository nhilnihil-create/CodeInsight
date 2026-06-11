#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define Rep(i, n) for(int i=0;i<n;++i)
#define rep(i, n) for(int i=1;i<=n;++i)
#define ll long long int
#define INF 100000000
#define INFLL 100000000000
#define MOD 1000000007
#define PI 3.14159265359
#define All(a) (a).begin(), (a).end()

using namespace std;
using P = pair<ll, ll>;
 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct Edge {
  int to;     
  ll weight; 
  Edge(int t, ll w) : to(t), weight(w) { }
};



int N;
bool base[30];
int d[60];

int main () {
  cin >> N;
  rep(i, N) {
    int tmp;
    cin >> tmp;

    if (base[tmp]) {
      if (base[24-tmp]) {
        cout << 0 << "\n";
        return 0;
      } else {
        base[24-tmp] = true;
      }
    } else {
      if (tmp == 0) {
        cout << 0 << "\n";
        return 0;
      }
      base[tmp] = true;
    }
  }

  vector<int> v;
  v.push_back(0);

  rep(i, 24) {
    if(base[i]) v.push_back(i);
  }
  sort(All(v));

  int n = v.size();
  int m = 1 << n;

//  Rep(i, n) {
//    cout << v[i] << "\n";
//  }

  int ans = 0;

  bool skip[30];
  for (int i=0;i<=24;++i) {
    if (base[i]) {
      if (i==0 || i== 24 || base[24-i]) {
        skip[i] = true;
      }
    }
  }


  Rep(bits, m) {
    bitset<28> bs(bits);

    int tmp = INF;
    bool flg = false;

    for (int i=0;i<n;++i) {
      for (int j=i+1;j<n;++j) {
        int k;
        if (bs[i]) {
          k = v[i];
        } else {
          if (skip[v[i]]) {
            flg = true;
            break;
          }
          k = 24 - v[i];
        }
        int l;
        if (bs[j]) {
          l = v[j];
        } else {
          if (skip[v[j]]) {
            flg = true;
            break;
          }
          l = 24 - v[j];
        }

        int dis = min(abs(k-l), 24-abs(k-l));

        tmp = min(tmp, abs(dis));
      }

      if (flg) {
        break;
      }
    }

    if(!flg) ans = max(ans, tmp);
  }

  cout << ans << "\n";
}
