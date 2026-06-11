#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int N;
    std::string s; 
    std::cin >> N >> s;
    

    /* cut文字列を分割する位置 0~cut-1, cut~N-1で分ける*/
    int res = 0;
    for (int cut = 1; cut < N; ++cut) {
      int tmp = 0;
      for (int i = 0; i < 26; ++i) {
        if (s.find('a'+i) < cut && s.find('a'+i, cut) != std::string::npos) {
          ++tmp;    
        }
      }      
      res = std::max(res, tmp);
    }

    std::cout << res << std::endl;

    return 0;
}
