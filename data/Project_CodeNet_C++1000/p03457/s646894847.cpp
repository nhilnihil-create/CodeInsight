#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 10e17
#define rep(i,n) for(long long i=0; i<n; i++)
#define repr(i,n,m) for(long long i=m; i<n; i++)
#define mod 1000000007
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<long long>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto&& itr : x) { cerr << (itr) << " "; }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> X(N), Y(N), T(N);
  repr(i, N, 0) {
    cin >> T[i] >> X[i] >> Y[i];
  }

  int x,y,time;
  x = 0, y = 0, time = 0;
  for (int i = 0; i < N; ++i) {
    int nx,ny,dist,rtime;
    nx = X[i], ny = Y[i], rtime = T[i] - time;
    dist = abs(x - X[i]) + abs(Y[i] - y);
    if (dist > rtime || rtime % dist == 1) {
      cout << "No" << endl;
      return 0;
    }

    x = nx, y = ny, time = T[i];
  }

  cout << "Yes" << endl;
}