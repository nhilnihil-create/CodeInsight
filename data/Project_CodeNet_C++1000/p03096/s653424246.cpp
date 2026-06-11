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
int col[210000];
ll a[210000];
vector<int> places[210000];

int main () {
  cin >> N;
  rep(i, N) cin >> col[i];
  rep(i, N) {
    places[col[i]].push_back(i);
  }

  a[0] = 1;

  rep(i, N) {
    int c = col[i];
    a[i] = a[i-1];
    
    int index = lower_bound(All(places[c]), i) - places[c].begin();

    if (index > 0) {
      int j = places[c][index - 1];
      if ((i-j) > 1) {
        a[i] += a[j];
        a[i] %= MOD;
      }
    }
  }

//  rep(i, N) {
//    cout << a[i] << "\n";
//  }

  cout << a[N] << "\n";
}