#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

int main(){
  string S;
  cin >> S;
  int ans=753;
  for(int i=0;i<S.size()-2;i++){
    string sub_S=S.substr(i,3);
    int num=atoi(sub_S.c_str());
    ans=min(ans,abs(753-num));
  }

  cout << ans << endl;

  return 0;
}
