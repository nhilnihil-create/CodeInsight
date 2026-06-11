#include<iostream>
#include<algorithm>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  char c1, c2, c3, c4; std::cin >> c1 >> c2 >> c3 >> c4;
  int a = (c1-'0')*10 + (c2-'0'), b = (c3-'0')*10+(c4-'0');
  int mm = std::min(a, b), yy = std::max(a, b);
  // MM: [1,12] YY: no limits
  if(mm == 0) std::swap(mm, yy);
  if(mm == 0 || mm > 12) fin("NA");
  if(1 <= yy && yy <= 12) fin("AMBIGUOUS");
  if(a == mm) fin("MMYY");
  fin("YYMM");
  return 0;
}
