#include <iostream>
#include <vector>
using namespace std;

#define ALL(x) begin(x), end(x)

int main() {
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  vector<int> v(S.size()+1,0);
  int c{};
  for (int i = 0, n = S.size(); i != n; ++i) {
    if (S.substr(i,2) == "AC") ++c;
    v[i+1] = c;
  }
  int l,r;
  for (int i = 0; i != Q; ++i) {
    cin >> l >> r;
    cout << v[r-1]-v[l-1] << endl;
  }
}
