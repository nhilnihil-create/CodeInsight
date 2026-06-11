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
#define lli long long int

using namespace std;
using P = pair<int,int>;

int main(){

  int N, D, X;
  cin >> N >> D >> X;

  int ans = 0;

  vector<int> vec(N);
  for (int i = 0; i < N; i++){
    cin >> vec.at(i);
  }

  for (int i = 0; i < D; i++) {
    for (int j = 0; j < N; j++) {
      if(i*vec.at(j)+1<=D){
        ans+= 1;
      }
    }
  }

  cout << ans+X << endl;

  return 0;
}