#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

// Acknowledgement: Special thanks to kyomukyomupurin, who developed this
// template.
template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
  return os << '(' << p.first << ", " << p.second << ')';
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  int n = 0;
  for (auto e : vec) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& st) {
  int n = 0;
  for (auto e : st) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::map<T, U>& mp) {
  int n = 0;
  for (auto e : mp) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
  for (T& e : vec) is >> e;
  return is;
}

#ifdef LOCAL
#define debug(...) \
  std::cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

void debug_out() { std::cerr << '\n'; }

template <class Head, class... Tail>
void debug_out(Head&& head, Tail&&... tail) {
  std::cerr << head;
  if (sizeof...(Tail) != 0) std::cerr << ", ";
  debug_out(std::forward<Tail>(tail)...);
}
using namespace std;
using int64 = long long;

int64 combination(int64 n, int64 p) {
  int64 bunshi = 1;
  int64 bunbo = 1;
  for (int64 i = n; i > n - p; i--) {
    bunshi *= i;
  }
  for (int64 i = 1; i <= p; i++) {
    bunbo *= i;
  }
  return bunshi / bunbo;
}

int main() {
  int N;
  cin >> N;
  vector<int64> A(N);
  cin >> A;
  for (int64 i = 1; i < N; i++) {
    A[i] += A[i - 1];
  }
  A.push_back(0);
  sort(A.begin(), A.end());
  int64 tmp = 1;
  vector<int64> num_of_identical_sum;
  for (int64 i = 1; i < N + 1; i++) {
    if (A[i - 1] == A[i]) {
      tmp++;
    } else {
      if (tmp != 1) {
        num_of_identical_sum.push_back(tmp);
      }
      tmp = 1;
    }
  }
  if (tmp != 1) {
    num_of_identical_sum.push_back(tmp);
  }
  int64 length_num_of_idencital_sum = num_of_identical_sum.size();
  int64 result = 0;
  for (int64 i = 0; i < length_num_of_idencital_sum; i++) {
    result += combination(num_of_identical_sum[i], 2);
  }
  cout << result << endl;
  return 0;
}