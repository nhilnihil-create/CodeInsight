#include <bits/stdc++.h>
using namespace std;

int check(int p){
  int ans = 0;
  while(p % 2 == 0){
    ++ans;
    p /= 2;
  }
  return ans;
}

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; ++i){
    cin >> a.at(i);
  }
  int res = 100000;
  for(int i = 0; i < n; ++i){
    res = min({res,check(a.at(i))});
  }
  cout << res;
}