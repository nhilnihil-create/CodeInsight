#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  vector<int64_t> Lucas(n+1);
  Lucas.at(0) = 2LL;
  Lucas.at(1) = 1LL;
  for(int i=2; i<=n; i++){
    Lucas.at(i) = Lucas.at(i-1) +Lucas.at(i-2);
  }
  cout << Lucas.at(n);
}