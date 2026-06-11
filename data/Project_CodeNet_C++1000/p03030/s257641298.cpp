#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

struct restaurant {
  int no;
  string name;
  int pt;
};

int cmp(const void *v1, const void *v2) {
  restaurant *r1 = (restaurant*)v1;
  restaurant *r2 = (restaurant*)v2;
  if (r1->name > r2->name) return 1;
  if (r1->name < r2->name) return -1;
  if (r1->pt > r2->pt) return -1;
  if (r1->pt < r2->pt) return 1;
  return 0; 
}

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  vector<int> p(n);
  rep(i, n) cin >> s[i] >> p[i];

  vector<pair<pair<string, int>, int>> r(n);
  rep(i, n) r[i] = make_pair(make_pair(s[i], -p[i]), i+1);
  sort(r.begin(), r.end());
  rep(i, n) cout << r[i].second << endl;
  return 0;
}