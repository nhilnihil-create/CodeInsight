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
  vector<int> A(5);
  int min_1=9;
  int index=-1;
  for(int i=0;i<5;i++){
    cin >> A.at(i);
    if(A.at(i)%10!=0){
      if(A.at(i)%10<=min_1){
	min_1=A.at(i)%10;
	index=i;
      }
    }
  }

  int ans=0;
  for(int i=0;i<5;i++){
    if(i==index) ans+=A.at(i);
    else{
      if(A.at(i)%10==0) ans+=A.at(i);
      else ans+=(A.at(i)/10)*10+10;
    }
  }

  cout << ans << endl;
  
  return 0;
}
