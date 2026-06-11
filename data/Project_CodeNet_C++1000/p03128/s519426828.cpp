#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>

template <typename C>
void print_container(const C &c, const std::string &name)
{
  std::cout << name << ": ";
  std::for_each(c.cbegin(), c.cend(),
                [](auto &x) { std::cout << x << ", "; });
  std::cout << std::endl;
}

int main()
{
  int N, M;
  std::cin >> N >> M;

  const std::vector<int> a_vs_m = {
    // 1  2  3  4  5  6  7  8  9
    0, 2, 5, 5, 4, 5, 6, 3, 7, 6
  };

  std::set<int> as;
  std::set<int> ms;
  std::map<int, int> m2a;
  for(int i=0; i<M; i++) {
    int a;
    std::cin >> a;
    as.insert(a);
    int m = a_vs_m[a];
    ms.insert(m);
    m2a[m] = std::max(m2a[m], a);
  }

  // the max number of digits by i-matches.
  // -1 if we cannot create a number.
  std::vector<int> dp(N+1);
  std::vector<std::string> dp_num(N+1);
  dp[0] = 0;
  dp_num[0] = "";

  for(int i=1; i<=N; i++) {
    dp[i] = -1;
    for(auto m: ms) {
      //std::cout << "i: " << i
      //          << " m: " << m
      //          << " i-m: " << i-m
      //          << " dp[i-m]" << (i-m >= 0 ? dp[i-m] : -1)
      //          << std::endl;

      if(m <= i && dp[i-m] >= 0) {
        int nd = dp[i-m] + 1;
        std::string nd_num = std::to_string(m2a[m]) + dp_num[i-m];
        if(dp[i] <= nd) {
          dp[i] = nd;
          if(dp[i] < 0 || dp_num[i][0] < nd_num[0]) {
            dp_num[i] = nd_num;
          }
        }
      }
    }
  }
  // print_container(dp, "dp");
  // print_container(dp_num, "dp_num");

  std::cout << dp_num[N] << std::endl;

  return 0;
}
