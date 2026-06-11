#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

struct dat {
  string name;
  int pnt, id;
  dat() {}
  dat(string name, int pnt, int id):
    name(name), pnt(pnt), id(id) {}
};

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int id = 0;
  vector<dat> v(n);
  for (auto &i : v) {
    string name;
    int pnt = 0;
    cin >> name >> pnt;
    i = dat(name, pnt, ++id);
  }
  sort(all(v), [](dat &a, dat &b) -> bool {
    if (a.name == b.name) return a.pnt > b.pnt;
    return a.name < b.name;
  });
  for (auto &i : v) cout << i.id << '\n';
}
