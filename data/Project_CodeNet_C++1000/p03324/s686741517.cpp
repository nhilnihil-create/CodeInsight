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
  int D,N;
  cin >> D >> N;

  if(N==100) printf("%d\n",101*(int)pow(100,D));
  else cout << N*pow(100,D) << endl;
  
  return 0;
}
