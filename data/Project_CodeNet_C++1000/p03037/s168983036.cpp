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

  int N, M, L, R;
  cin >> N >> M;
  int ans = 0;

  int l = 0, r = 1e9;
  for (int i = 0; i < M; i++) {
    cin >> L >> R;
    l = max(l,L);
    r = min(r,R);
  }
  // cout << l << endl;
  // cout << r << endl;

  if(l>r){
    cout << 0 << endl;
  }else{
    cout << r-l+1 << endl;
  }

  return 0;
}