#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

void rot45(int &x,int &y){
  int tmp = x + y;
  x = x - y;
  y = tmp;
}

signed main(){

  int n; cin >> n;
  vector<int> x(n),y(n);
  vector<int> s(n); //関節iとi+1の差の偶奇が等しければok
  for(int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
    s[i] = x[i] + y[i];
    if((s[i] - s[0])%2 != 0){
      cout << -1 << endl;
      return 0;
    }
  }

  vector<int> v;
  for(int i = 30; i >= 0; i--) v.push_back(1 << i);
  if(s[0]%2 == 0) v.push_back(1);

  cout << v.size() << endl;
  for(int p : v) cout << p << " ";
  cout << endl;

  for(int i = 0; i < n; i++){
    rot45(x[i], y[i]);
    for(int p : v){
      if(x[i] >= 0 && y[i] >= 0){
        cout << "R";
        x[i] -= p, y[i] -= p;
      }
      else if(x[i] >= 0 && y[i] < 0){
        cout << "D";
        x[i] -= p, y[i] += p;
      }
      else if(x[i] < 0 && y[i] < 0){
        cout << "L";
        x[i] += p, y[i] += p;
      }
      else if(x[i] < 0 && y[i] >= 0){
        cout << "U";
        x[i] += p, y[i] -= p;
      }
    }
    cout << endl;
  }

  return 0;
}
