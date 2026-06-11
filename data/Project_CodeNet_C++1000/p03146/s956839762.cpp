#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <cmath>
#define ll long long

using namespace std;
using P = pair<int,int>;

int main(){

  int s;
  cin >> s;
  int ans = 0;
  vector<int> vec(1000001);

  int cnt = 1;
  if(s == 1 || s == 2){
    cout << 4 << endl;
    return 0;
  } else {
    for (int i = 0; i < 1000000; i++) {
      if(s%2 == 0){
        s = s/2;
        vec.at(i) = s;
      } else {
        s = 3*s+1;
        vec.at(i) = s;
      }
      cnt++;
      if(s == 1) break;
    }
    cout << cnt+1 << endl;
    return 0;
  }

  return 0;
}