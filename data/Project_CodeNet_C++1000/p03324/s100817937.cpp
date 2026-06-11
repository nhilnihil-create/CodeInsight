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

  int D, N;
  cin >> D >> N;

  if(D == 0){
    if(N == 100) cout << 101 << endl;
    else cout <<  N << endl;
  } else if (D == 1){
    if(N == 100) cout << 101*100 << endl;
    else cout <<  N*100 << endl;
  } else if (D == 2){
    if(N == 100) cout << 101*10000 << endl;
    else cout <<  N*10000 << endl;
  }


  return 0;
}