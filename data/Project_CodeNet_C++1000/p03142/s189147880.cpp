#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <climits>
#include <random>
#include <iomanip>

using namespace std;
using P = pair<long, long>;

typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define fillInt(xs, x)        \
  for (int i = 0; i < (x); i++) \
    scanf("%d", &xs[i]);
#define fillLong(xs, x)       \
  for (int i = 0; i < (x); i++) \
    scanf("%ld", &xs[i]);
#define fillDouble(xs, x)       \
  for (int i = 0; i < (x); i++) \
    scanf("%lf", &xs[i]);
#define fillString(xs, x)       \
  for (int i = 0; i < (x); i++) \
    cin >> xs[i];
#define sortv(xs) sort(xs.begin(), xs.end())
#define sortvinv(xs) sort(xs.begin(), xs.end(), std::greater<long>())
#define lbv(xs, x) lower_bound(xs.begin(), xs.end(), x) - xs.begin()
#define ubv(xs, x) upper_bound(xs.begin(), xs.end(), x) - xs.begin()
#define bs(xs, x) binary_search(xs.begin(), xs.end(), x)
#define index_of(as, x) \
  distance(as.begin(), lower_bound(as.begin(), as.end(), x))
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define concat(xs, ys) (xs).insert((xs).end(), (ys).begin(), (ys).end())

const int mod = 1000000007;
const int MAX_V = 100005;

vector<int> G[MAX_V];
int oya[MAX_V];

int sanshoCnt[MAX_V];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  rep(i, n+m-1) {
    int a, b;
    cin >> a >> b;
    a--;b--;
    G[a].push_back(b);
    sanshoCnt[b]++;
  }

  int root = -1;
  rep(i, n) {
    if (!sanshoCnt[i]) {
      root = i;
    }
  }

  queue<int> que;
  que.push(root);

  while (!que.empty()) {
    int v = que.front();
    que.pop();

    for (int nv : G[v]) {
        sanshoCnt[nv]--;
        if (!sanshoCnt[nv]) {
          oya[nv] = v+1;
          que.push(nv);
        }
    }
  }

  rep(i, n) {
    cout << oya[i] << endl;
  }
}