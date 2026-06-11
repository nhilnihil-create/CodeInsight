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


vector<int> enum_div(int n){
  vector<int> ret;
  for(int i = 1 ; i*i <= n ; ++i){
    if(n%i == 0){
      ret.push_back(i);
      if(i != 1 && i*i != n){
        ret.push_back(n/i);
      }
    }
  }
  return ret;
}

int main(){

  int N;
  cin >> N;
  int ans = 0;

  for (int i = 1; i <= N; i++) {
    vector<int> vec(i);
    vec = enum_div(i);
    int size = vec.size()+1;
    if(i%2 != 0 && size == 8) ans++;
  }

  cout << ans << endl;

  return 0;
}