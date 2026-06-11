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

struct mise{
  string S;
  int P;
  int N;
};

bool mycomp(const mise& lh, const mise& rh){
  if(lh.S==rh.S){
    return lh.P > rh.P;
  }
  else
    return lh.S < rh.S;
}
  
int main(){
  int N;
  cin >> N;
  vector<mise> rest(N);

  string S;
  int P;
  mise temp;
  for(int i=0;i<N;++i){
    cin >> temp.S >> temp.P;
    temp.N=i+1;
    rest.at(i)=temp;
  }

  sort(rest.begin(),rest.end(),mycomp);

  for(int i=0;i<N;++i) cout << rest.at(i).N << endl;
  

  return 0;
}
