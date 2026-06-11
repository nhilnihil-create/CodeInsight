#include <bits/stdc++.h>
using namespace std;

template<class T> class CumulativeSum2 {
private:
  vector<vector<T>> data;
public:
  CumulativeSum2(int W, int H) : data(W + 1, vector<int>(H + 1, 0)) {}
  void add(int x, int y, T z) {
    x++, y++;
    if (x >= data.size() || y >= data.at(0).size()) return;
    data.at(x).at(y) += z;
  }
  void build() {
    for (int i = 1; i < data.size(); i++) {
      for (int j = 1; j < data.at(i).size(); j++) {
        data.at(i).at(j) += data.at(i).at(j - 1) + data.at(i - 1).at(j) - data.at(i - 1).at(j - 1);
      }
    }
  }
  T query(int sx, int sy, int gx, int gy) const {
    return (data.at(gx).at(gy) - data.at(sx).at(gy) - data.at(gx).at(sy) + data.at(sx).at(sy));
  }
};

int main() {
  int N, M, Q;
  cin >> N >> M >> Q;
  CumulativeSum2<int> CS2(N, N);
  for (int i = 0; i < M; i++) {
    int L, R;
    cin >> L >> R;
    CS2.add(--L, --R, 1);
  }
  CS2.build();
  for (int i = 0; i < Q; i++) {
    int p, q;
    cin >> p >> q;
    --p;
    cout <<  CS2.query(p, p, q, q) << "\n";
  }
}