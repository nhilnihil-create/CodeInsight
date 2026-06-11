#include <bits/stdc++.h>

using namespace std;
using P = pair<long, long>;

typedef long long int ll;

#define EPS (1e-7)
#define INF (1e18)
#define PI (acos(-1))

#define sortv(xs) sort(xs.begin(), xs.end())
#define sortvinv(xs) sort(xs.begin(), xs.end(), greater<long>())
#define lbv(xs, x) lower_bound(xs.begin(), xs.end(), x) - xs.begin()
#define ubv(xs, x) upper_bound(xs.begin(), xs.end(), x) - xs.begin()
#define bs(xs, x) binary_search(xs.begin(), xs.end(), x)
#define index_of(as, x) \
  distance(as.begin(), lower_bound(as.begin(), as.end(), x))
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define concat(xs, ys) (xs).insert((xs).end(), (ys).begin(), (ys).end())

const int mod = 1000000007;


long depths[100005];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  long n;
  cin >> n;

  vector<long> res;
  if (n == 3) {
    res.push_back(2);
    res.push_back(5);
    res.push_back(63);
  } else if (n == 4) {
    res.push_back(2);
    res.push_back(5);
    res.push_back(20);
    res.push_back(63);
  } else if (n < 21) {
    res.push_back(2);
    res.push_back(3);
    res.push_back(4);
    res.push_back(6);
    res.push_back(9);
    n-=5;
    rep(i, 1000) {
    if(n == 0) {
      break;
    } else {
      res.push_back(i*30+30);
      n--;
    }
    }
  } else {
    rep(i, 1000) {
      if(n == 0) {
        break;
      } else if (n >= 21) {
        rep(j_, 30) {
          int j = j_+1;
          if(j%2 == 0 || (j%3==0 && j%5) || (j%5==0 && j%3)) {
            res.push_back(i*30+j);
            n--;
          }
        }
      } else {
        res.push_back(i*30+30);
        n--;
      }
    }
  }

  rep(i, res.size()) {
    cout << res[i] << endl;
  }
}
