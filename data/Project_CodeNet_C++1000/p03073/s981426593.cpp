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

int main(){

  string S;
  cin >> S;
  int ans = 0;

  bool flag = true;
  if(S[0] == '0') flag = false;
  else flag = true;

  for (int i = 1; i < S.size(); i++) {
    if(flag == false){
      if(S[i] == '0'){
        S[i] = '1';
        ans++;
      }
      flag = true;
    } else {
      if(S[i] == '1'){
        S[i] = '0';
        ans++;
      }
      flag = false;
    }
  }

  cout << ans << endl;

  return 0;
}