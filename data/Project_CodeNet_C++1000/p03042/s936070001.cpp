#include<iostream>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  char c1, c2, c3, c4; std::cin >> c1 >> c2 >> c3 >> c4;
  int a = (c1-'0')*10 + (c2-'0'), b = (c3-'0')*10+(c4-'0');
  auto is_month = [](int m)->bool { return 1 <= m && m <= 12; };
  if(is_month(a)) {
    if(is_month(b)) fin("AMBIGUOUS");
    fin("MMYY");
  }
  if(is_month(b)) fin("YYMM");
  fin("NA");
  return 0;
}
