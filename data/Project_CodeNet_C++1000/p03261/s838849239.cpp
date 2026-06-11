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
  int N;
  cin >> N;
  set<string> word;
  string temp,prev;
  bool flag=true;
  for(int i=0;i<N;++i){
    cin >> temp;
    if(word.count(temp)){
      flag=false;
    }
    word.insert(temp);
    if(i==0){
      prev=temp;
      continue;
    }
    //cout << "now:" << *begin(temp) << " prev:" << *(prev.end()-1) << endl;
    if(*begin(temp)!=*(prev.end()-1)){
      flag=false;
    }
    prev=temp;	
  }

  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
