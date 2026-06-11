#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  long long N;
  vector<long long> A, B, C;
  cin >> N;
  long long ll;
  rep(i, N) {
    cin >> ll;
    A.push_back(ll);
  }
  rep(i, N) {
    cin >> ll;
    B.push_back(ll);
  }
  rep(i, N) {
    cin >> ll;
    C.push_back(ll);
  }
  sort(A.begin(), A.end());
  sort(C.begin(), C.end());
  long long c = 0;
  for (auto b : B) {
    long long lower = lower_bound(A.begin(), A.end(), b) - A.begin();
    long long greater = C.end() - upper_bound(C.begin(), C.end(), b);
    c += lower * greater;
  }
  cout << c << endl;
  return 0;
}
