#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> x(n), y(n), h(n);
  int p;
  for(int i = 0; i < n; ++i){
    cin >> x.at(i) >> y.at(i) >> h.at(i);
    if(h.at(i) > 0) p = i;
  }
  
  long long ax, ay, ah;
  for(int i = 0; i <= 100; ++i){
    for(int j = 0; j <= 100; ++j){
      long long hi = h.at(p) + abs(i-x.at(p)) + abs(j-y.at(p));
      bool ok = true;
      for(int k = 0; k < n; ++k){
        long long t = h.at(k) + abs(i-x.at(k)) + abs(j-y.at(k));
        if(h.at(k) > 0){
          if(t != hi) ok = false;
        }
        else{
          if(t < hi) ok = false;
        }
      }
      if(ok) ax = i, ay = j, ah = hi;
    }
  }
  
  cout << ax << ' ' << ay << ' ' << ah << endl; 
}