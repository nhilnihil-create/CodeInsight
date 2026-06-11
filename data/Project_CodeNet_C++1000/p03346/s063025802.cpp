#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <functional>
#include <map>
#include <set>
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
bool d[210000];

int main () {
  cin >> N;
  Rep(i, N) {
    int tmp;
    cin >> tmp;

    if (d[tmp-1]) {
      d[tmp-1] = false;
      d[tmp] = true;
    } else {
      d[tmp] = true;
    }
  }

  int ans = 0;
  int tmp = 0;

  rep(i, N) {
    if (d[i]) {
      ans = max(ans, tmp + 1);
      tmp = 0;
    } else {
      tmp++;
    }
  }

  cout << N - ans << "\n";
}