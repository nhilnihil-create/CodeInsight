#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(M);
  for (int i = 0; i < N; ++i) {
    int num;
    cin >> num;
    for (int j = 0; j < num; ++j) {
      int v; cin >> v; --v;
      a[v]++;
    }
  }
  int res = 0;
  for (int i = 0; i < M; ++i) if (a[i] >= N) ++res;
  cout << res << endl;
}