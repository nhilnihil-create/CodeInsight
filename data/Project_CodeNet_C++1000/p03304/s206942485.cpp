#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

using Pair = pair<int, int>;
using lint = long long;

// const int mod = 1e9 + 7;
// const int mod = 998244353;

template <typename T> vector<T> make_v(size_t a) { return vector<T>(a); }

template <typename T, typename... Ts> auto make_v(size_t a, Ts... ts) {
  return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

int main(){
  cout << fixed << setprecision(16) << endl;
  long double n, m, d;
  cin >> n >> m >> d;
  if(d==0){
    cout << (m - 1) / n << endl;
  }else{
    cout << (n - d) * 2 / n / n * (m - 1) << endl;
  }
}
