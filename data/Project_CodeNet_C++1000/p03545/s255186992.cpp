#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef long long ll;

int main() {
  int a, b, c, d;
  string s;
  cin >> s;
  a = s[0]-'0';
  b = s[1]-'0';
  c = s[2]-'0';
  d = s[3]-'0';

  vi vb, vc, vd;
  
  vb.pb(b);
  vb.pb(-b);
  vc.pb(c);
  vc.pb(-c);
  vd.pb(d);
  vd.pb(-d);
  
  for (int ib : vb) {
    for (int ic: vc) {
      for (int id : vd) {
        if (a+ib+ic+id == 7) {
          cout << a;
          if (ib >= 0) {
            cout << "+";
          }
          cout << ib;
          if (ic >= 0) {
            cout << "+";
          }
          cout << ic;
          if (id >= 0) {
            cout << "+";
          }
          cout << id;
          
          cout << "=7";
          return 0;
        }
      }
    }
  }
  
  return 0;
}