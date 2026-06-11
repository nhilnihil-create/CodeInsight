#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <bitset>
using namespace std;
typedef long long ll;
const ll inf = 4e18;
const ll mod = 1e9+7;
#define print(X) cout << X << endl
#define vvi vector<vector<int>>
#define vec vector
#define pq priority_queue
#define all(v) (v).begin(), (v).end()
#define uniqueV(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());
#define rep(i, n) for (ll (i) = (0); (i) < (n); ++(i))
#define repp(i, m, n) for (ll (i) = (m); (i) < (n); ++(i))
#define repd(i, m, n) for (ll (i) = (m); (i) > (n); --(i))
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) cerr<<"("<<#x<<", "<<#y<<") = "<<"("<<x<<", "<<y<<")"<<endl;
#define debug3(x, y, z) cerr<<"("<<#x<<", "<<#y<<", "<<#z<<") = "<<"("<<x<<", "<<y<<", "<<z<<")"<<endl;
#define debugB(value, size) cerr<<#value<<": "<<bitset<size>(value) << endl;
#define line() cerr << "---------------" << endl;

template <class T>
string join(const vector<T>& v, const char* delim = 0) {
  string s;
  if (!v.empty()) {
    s += v[0];
    for (decltype(v.size()) i = 1, c = v.size(); i < c; ++i) {
      if (delim) s += delim;
      s += v[i];
    }
  }
  return s;
}
//         100
// .........
// .........
// #########
// .########

int main(void)
{
    ll A,B;
    ll N=100;
    cin >> A >> B;
    vec<vec<char>> s(N, vec<char>(N, '#'));

    rep (y,N/2) {
        rep (x,N) {
            s[y][x] = '.';
        }
    }
    repp (y,N/2,N) {
        rep (x,N) {
            s[y][x] = '#';
        }
    }
    A -= 1;
    B -= 1;
    ll x, y;
    x = 0;
    y = 0;
    while (B--) {
        s[y][x] = '#';
        x+=2;
        if (x>=N) {
            x=0;
            y+=2;
        }
    }
    x = 0;
    y = N-1;
    while (A--) {
        s[y][x] = '.';
        x+=2;
        if (x>=N) {
            x=0;
            y-=2;
        }
    }
    print(N<<" "<<N);
    rep(y,N) {
        print(join(s[y]));
    }
}
