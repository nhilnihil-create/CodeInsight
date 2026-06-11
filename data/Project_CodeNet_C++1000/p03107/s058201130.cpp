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
#include <stack>
using namespace std;
using ll = long long;

int main(){
  string S;
  cin >> S;

  stack<char> s;
  int ans=0;

  for(int i=0;i<S.size();i++){
    if(s.empty()){
      s.push(S.at(i));
      continue;
    }
    if(s.top()!=S.at(i)){
      ans+=2;
      s.pop();
    }
    else s.push(S.at(i));
  }

  cout << ans << endl;
  
  return 0;
}
