#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <climits>
#include <utility>
typedef long long ll;
using namespace std;

int main(void){
  ll n;
  cin >> n;

  if(n==0){
    cout << 0 << endl;
    return 0;
  }

  vector<bool> out;
  out.clear();
  ll tmp = 1;
  while(n!=0){
    if(n%(abs(tmp)*2)!=0){
      out.push_back(1);
      n -= tmp;
    }
    else{
      out.push_back(0);
    }
    tmp *= -2;
  }

  for(int i=out.size()-1;i>=0;i--){
    cout << out[i];
  }
  cout << endl;

  return 0;
}
