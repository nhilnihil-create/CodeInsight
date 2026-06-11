#include <iostream>
#include <vector>
#include <set>
#include <map>

#define rep(i,n) for(int i=0;i<(int)n;++i)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

constexpr int inf = (int)1e9;
constexpr double INF = 1e12, EPS = 1e-9;
constexpr int MX = 2010;
constexpr int mod = inf + 7;

int n, m, q, a[MX];
int L[MX][MX], R[MX][MX];
int memo[MX][MX];

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  ll min = inf;

  for (int ci = 0; ci <= max(X, Y) * 2; ci += 2) {
    int ai = max(0, X - ci / 2);
    int bi = max(0, Y - ci / 2);
    int sum = A * ai + B * bi + C * ci;
    if (sum < min) min = sum;
  }

  cout << min << endl;
}