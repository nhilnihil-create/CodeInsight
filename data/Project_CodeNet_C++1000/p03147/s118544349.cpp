#include <algorithm>
#include <iostream>

int main()
{
  int n, tmp, cnt, pre;
  cnt = 0;
  tmp = 0;
  int min_cnt = 0;
  int maxv = 0;
  bool judge = true;
  std::cin >> n;
  while (cnt < n) {
    pre = tmp;
    std::cin >> tmp;
    if (pre > tmp && judge) {
      maxv = pre;
      judge = false;
    } else if (pre < tmp && judge == false) {
      judge = true;
      min_cnt += (maxv - pre);
      maxv = 0;
    }
    cnt++;
  }
  min_cnt += tmp;
  if (judge == false) {
    maxv = min_cnt += (maxv - tmp);
  }
  std::cout << min_cnt << std::endl;
  return 0;
}
