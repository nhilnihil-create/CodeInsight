#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<string> w(n);
  bool ok = true;
  for(int i= 0; i< n; i++){
    cin >> w.at(i);
  }
  for(int i = 1; i < n; i++){
    if(w.at(i).at(0) != w.at(i-1).at(w.at(i-1).size()-1)) ok = false;
  }
  sort(w.begin(), w.end());
  for(int i = 0; i < n-1; i++){
    if(w.at(i) == w.at(i+1)) ok = false;
  }
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
       