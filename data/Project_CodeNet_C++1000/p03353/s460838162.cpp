#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>

int main(){
  std::string s;
  std::cin >> s;
  int K;
  scanf("%d", &K);
  int n = s.length();
  std::vector<std::string > vec;
  for (int i=0; i<n; i++){
    std::string moji;
    //std::cout << "S[" << i << "]=" << s[i] << std::endl;
    //std::cout << "moji=" << moji << std::endl;
    for (int j=i; j<std::min(i+6,n); j++){
      moji += s[j];
      //std::cout << "Sj[" << j << "]=" << s[j] << std::endl;
      vec.push_back(moji);
      //std::cout << "moji=" << moji << std::endl;
    }
  }
  std::sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  //printf("size=%lu\n", vec.size());
  std::cout << vec[K-1] << std::endl;
  return 0;
}
