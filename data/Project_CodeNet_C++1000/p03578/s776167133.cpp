#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n;
  map<int, int> d, t;
  for(int i = 0; i < n; i++){
    int k;
    cin >> k;
    d[k]++;
  }
  cin >> m;
  for(int i = 0; i < m; i++){
    int k;
    cin >> k;
    t[k]++;
  }
  
  bool ok = true;
  if(m > n) ok = false;
  else{
    for(auto now : t){
      int dif = now.first, num = now.second;
      if(!d.count(dif)) ok = false;
      else if(d.at(dif) < num) ok = false;
      if(!ok) break;
    }
  }
  
  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
}