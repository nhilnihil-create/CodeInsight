#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  int n;
  cin >> n;
  vector<string> w(n);
  set<string> s;
  int ans=1;
  string f;
  cin >>f;
  w[0] =f;
  s.insert(f);
  
  for(int i=1;i<n;i++){
    string g;
    cin >> g;
    w[i] = g;
    s.insert(g);
    
    if(w[i-1].at(w[i-1].size()-1) != w[i].at(0)) {
      ans =0;
      break;
    }
    
  }
  if(s.size()!= n) ans =0;
  
  if(ans == 0) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
  
}
