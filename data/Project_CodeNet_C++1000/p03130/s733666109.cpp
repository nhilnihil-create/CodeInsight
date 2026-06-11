#include <bits/stdc++.h>
using namespace std;
int main() {
  map<int,int>Mp;
  for(int i = 0; i < 6; i++) {
      int a;cin >> a;
      Mp[a]++;
  }
  int X = 0,Y = 0;
  for(pair<int,int> x:Mp) {
      if(x.second == 1) {
          X++;
      }
      else {
          Y++;
      }
  }
  if(X == 2 && Y == 2) {
      cout <<"YES"<< endl;
  }
  else {
      cout << "NO" << endl;
  }
}