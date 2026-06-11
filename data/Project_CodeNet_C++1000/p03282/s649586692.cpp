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

  string S;
  ll K;
  cin >> S >> K;

 for (int i = 0; i < min((long long)S.size(), K); i++) {
    if(S[i] >= '2') {
      cout << S[i] << endl;
      return 0;
    }
  }
  cout << '1' << endl;

  return 0;
}