#include<bits/stdc++.h>

using namespace std;
vector<pair<pair<int, int>, int>> edges;

void brute(int x, int len) {
  if(x == 19) {
    cout << "yeh: " << len << endl;
    return;
  }

  for(auto &e : edges) if(e.first.first == x) {
    brute(e.first.second, len + e.second);
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int L; cin >> L;
  L--;


  vector<int> before(20, -1);

  for(int i = 0; i + 1 < 20; ++i) {
    int c = 20 - i - 2;
    edges.emplace_back(make_pair(i, i + 1), 0);
    if((1 << (c + 1)) <= L) {
      edges.emplace_back(make_pair(i, i + 1), (1 << c));
      before[c] = i;
    }
  }

  if(__builtin_popcount(L) == 1) {
    edges.emplace_back(make_pair(0, 19), L);
  }
  else {

    int last_bit = -1, last_vertex = 0, sum = 0;
    for(int i = 20; i >= 0; --i) {
      if(L & (1 << i)) {
        if(last_bit != -1) {
          if(i > 0) edges.emplace_back(make_pair(0, before[i - 1]), sum);
          else edges.emplace_back(make_pair(0, 19), L - 1);
        }
        sum += 1 << i;
        last_bit = i;
      }
    }
    edges.emplace_back(make_pair(0, 19), L);
  }

  cout << 20 << " " << edges.size() << endl;
  for(auto &e : edges) {
    cout << e.first.first + 1 << " " << e.first.second + 1 << " " << e.second << endl;
  }

  //brute(0, 0);

  return 0;
}
