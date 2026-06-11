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
  string S,T;
  cin >> S >> T;
  string ans="No";
  
  for(int i=0;i<S.size();++i){
    string temp_S=S;
    char temp_c=*(S.end()-1);
    temp_S.pop_back();
    temp_S=temp_c+temp_S;
    if(temp_S==T){
      ans="Yes";
      break;
    }
    S=temp_S;
  }

  cout << ans << endl;

  return 0;
}
