#include <bits/stdc++.h>
#define loop(n) for (int ngtkana_is_genius = 0; ngtkana_is_genius < int(n); ngtkana_is_genius++)
#define rep(i, begin, end) for(int i = int(begin); i < int(end); i++)
#define lint long long
auto cmn = [](auto& a, auto b){if (a > b) {a = b; return true;} return false;};
auto cmx = [](auto& a, auto b){if (a < b) {a = b; return true;} return false;};

int main()
{
  std::cin.tie(0); std::cin.sync_with_stdio(false);
  int n; std::cin >> n;
  std::vector<std::tuple<int, int, int>> data;
  int S = 0;
  for (auto i = 0; i < n; i++)
  {
    int w, s, v;
    std::cin >> w >> s >> v;
    data.emplace_back(w, s, v);
    cmx(S, s + w);
  }
  std::sort(data.begin(), data.end(), [](auto p, auto q){
    return std::get<0>(p) + std::get<1>(p)
         < std::get<0>(q) + std::get<1>(q);
  });
  auto dp = std::vector<lint>(S + 1, 0);
  for (auto i = 0; i < n; i++)
  {
    int w, s, v;
    std::tie(w, s, v) = data.at(i);
    for (auto j = s; j >= 0; j--)
    {
      cmx(dp.at(j + w), dp.at(j) + v);
    }
  }
  auto ret = *std::max_element(dp.begin(), dp.end());
  std::cout << ret << std::endl;
  return 0;
}