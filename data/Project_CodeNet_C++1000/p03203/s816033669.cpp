#include <bits/stdc++.h>

#define int long long

#define R first

#define C second

using namespace std;

int h, w, n;

vector<vector<int>> p;

int32_t main() {

  ios_base::sync_with_stdio(0);

  cin >> h >> w >> n;
  swap(h, w) ;

  p.resize(h);

  map<pair<int, int>, int> M;

  for (int i = 0; i < n; ++i) {

    int r, c;

    cin >> r >> c;
    swap(r, c) ;

    r--; c--;

    p[r].push_back(c);

    M[make_pair(r, c)] = 1;

  }

  for (int i = 0; i < h; ++i) {

    sort(begin(p[i]), end(p[i]));

  }

  vector<int> cs;

  int c = 0;

  int r = 0;

  cs.push_back(c);

  for (; r < h; ++r) {

    if (c + 1 < w && M[make_pair(r, c + 1)]) {

      //cerr << "A\n";

      break;

    }

    c++;

    while ((r + 1 == h || M[make_pair(r + 1, c)]) && (c + 1 < w && !M[make_pair(r, c + 1)])) {

      c++;

    }

    //cerr << "c=" << c << "\n";

    if (!(r + 1 == h || M[make_pair(r + 1, c)])) {

      cs.push_back(c);

    } else {

      //cerr << "B\n";

      break;

    }

  }

  int res = w + h;

  for (int i = 0; i < cs.size(); ++i) {

    //cerr << "i = " << i << ", cs = " << cs[i] << "\n";

    int c = cs[i];

    int q = lower_bound(begin(p[i]), end(p[i]), c + 1) - begin(p[i]);

    int t = w - 1;

    if (q < p[i].size()) {

      t = p[i][q] - 1;

    }

    int r = t;

    if (c == t) {

      r = t;

    } else {

      r += 1;

    }

    //cerr << "t = " << t << ", r = " << r << "\n";

    res = min(res, t + 1);

  }

  

  cout << res << "\n";

  //  ...

  //  ...

  //  .#.

  return 0;

}

