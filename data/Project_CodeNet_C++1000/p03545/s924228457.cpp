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
  vector<int> a(4);
  for(int i=0;i<4;++i) a.at(i)=S.at(i)-'0';

  vector<char> op(3);
  if     (a[0]+a[1]+a[2]+a[3]==7){
    op[0]='+'; op[1]='+'; op[2]='+';
  }
  else if(a[0]+a[1]+a[2]-a[3]==7){
    op[0]='+'; op[1]='+'; op[2]='-';
  }
  else if(a[0]+a[1]-a[2]+a[3]==7){
    op[0]='+'; op[1]='-'; op[2]='+';
  }
  else if(a[0]+a[1]-a[2]-a[3]==7){
    op[0]='+'; op[1]='-'; op[2]='-';
  }
  else if(a[0]-a[1]+a[2]+a[3]==7){
    op[0]='-'; op[1]='+'; op[2]='+';
  }
  else if(a[0]-a[1]+a[2]-a[3]==7){
    op[0]='-'; op[1]='+'; op[2]='-';
  }
  else if(a[0]-a[1]-a[2]+a[3]==7){
    op[0]='-'; op[1]='-'; op[2]='+';
  }
  else if(a[0]-a[1]-a[2]-a[3]==7){
    op[0]='-'; op[1]='-'; op[2]='-';
  }

  for(int i=0;i<3;++i) cout << a.at(i) << op.at(i);
  cout << a.at(3) << "=7" << endl;

  return 0;
}
