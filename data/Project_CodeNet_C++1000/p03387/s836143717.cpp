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
  vector<int> a(3);
  cin >> a[0] >> a[1] >> a[2];

  int ans=0;
  while(!(a[0]==a[1] && a[1]==a[2])){
    sort(a.begin(),a.end());
    if(a[1]==a[2]){
      a[0]+=2;
      ++ans;
    }
    else if(a[0]==a[1]){
      ++a[0];
      ++a[1];
      ++ans;
    }
    else{
      a[0]+=2;
      ++ans;
    }
  }

  cout << ans << endl;
  
  return 0;
}
