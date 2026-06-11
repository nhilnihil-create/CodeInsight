#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
//#include <functional>
#include <queue>
//#include <stack>
//#include <set>
#include <cmath>
//#include <bitset>
#include <map>
using namespace std;
typedef long long ll;

int main() {
  int N[4];
  for(int i=0; i<4; i++){
    cin >> N[i];
  }
  int count[4]={};
  for(int i=0; i<4; i++){
    if(N[i] == 1) count[0]=1; 
    if(N[i] == 9) count[1]=1;
    if(N[i] == 7) count[2]=1;
    if(N[i] == 4) count[3]=1;
  }
  if (count[0] && count[1] && count[2] && count[3]) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;

}
