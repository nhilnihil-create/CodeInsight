//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>
#include <deque>
#include <set>

using namespace std;

const int nmax = 1e9 + 7;
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;

int main(){
  string S; cin >> S;

  if (S[0] != '1' || S[S.length() - 1] != '0' || S[S.length() - 2] != '1'){
    cout << -1 << endl;
    return 0;
  }

  for (int i = 0; i < S.length() - 1; i++){
    if (S[i] != S[S.length() - 2 - i]){
      cout << -1 << endl;
      return 0;
    }
  }

  int half;
  for (int i = 0; i < S.length() - 1; i++){
    if (i > S.length() - 2 - i){
      break;
    }
    if (S[i] == S[S.length() - 2 - i] && S[i] == '1'){
      half = i + 1;
    }
  }

  int now = 1;
  for (int i = 1; i < half; i++){
    cout << now << " " << i + 1 << endl;
    if (S[i - 1] == '1') now = i + 1;
  }

  cout << now << " " << half + 1 << endl;
  
  for (int i = half + 2; i <= S.length(); i++){
    cout << half + 1 << " " << i << endl;
  }
  

  return 0;
}
