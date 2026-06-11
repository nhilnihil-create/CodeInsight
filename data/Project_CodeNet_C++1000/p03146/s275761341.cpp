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
#include <set>
using namespace std;
using ll = long long;

int main(){
  int s;
  cin >> s;
  set<int> a;
  a.insert(s);

  int next=s;
  int i=1;
  while(1){
    if(next%2==0){
      next=next/2;
    }
    else{
      next=3*next+1;
    }
    ++i;
    if(a.count(next)) break;
    else a.insert(next);
  }

  cout << i << endl;
  
  return 0;
}
