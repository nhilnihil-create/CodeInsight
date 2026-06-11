#include <bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;

const ll MOD = (ll)1e9 + 7;
const ll HIGHINF = (ll)1e18;

int main(){
  string s;
  ll x, y;
  cin >> s >> x >> y;
  s += "T";
  V<bool> xdp(2 * (s.size() - 1) + 1, false), prex(2 * (s.size() - 1) + 1, false);
  V<bool> ydp(2 * (s.size() - 1) + 1, false), prey(2 * (s.size() - 1) + 1, false);
  ll d = 0, i = 0;
  for (ll si=0; si<s.size(); si++) {
    if (s.at(si)=='F') d++;
    else {
      if (!i) {
        prex.at(d + (s.size() - 1)) = true;
        prey.at(s.size()-1) = true;
      } else if (i % 2 == 1) {
        for (ll yi=0; yi<ydp.size(); yi++) {
          if (yi < d) ydp.at(yi) = prey.at(yi+d);
          else if (yi > ydp.size()-d-1) ydp.at(yi) = prey.at(yi-d);
          else {
            ydp.at(yi) = prey.at(yi+d) || prey.at(yi-d);
          }
        }
        prey = ydp;
        ydp = V<bool>(2 * (s.size() - 1) + 1, false);
      } else {
        for (ll xi=0; xi<xdp.size(); xi++) {
          if (xi < d) xdp.at(xi) = prex.at(xi+d);
          else if (xi > xdp.size()-d-1) xdp.at(xi) = prex.at(xi-d);
          else {
            xdp.at(xi) = prex.at(xi+d) || prex.at(xi-d);
          }
        }
        prex = xdp;
        xdp = V<bool>(2 * (s.size() - 1) + 1, false);
      }
      i++; d=0;
    }
  }
  if (prey.at(y+s.size()-1) && prex.at(x+s.size()-1)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}