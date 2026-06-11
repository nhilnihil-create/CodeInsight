#include <bits/stdc++.h>
using namespace std;
int main(){
  string s; cin >> s;
  int k;  cin >> k;
  vector<string> v;
  for(int i=0 ; i<s.size() ; i++){
    for(int j=1 ; j<=k ; j++){
        string tmp = s.substr(i,j);
        v.push_back(tmp);
    }
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(),v.end()), v.end());
  cout << v[k-1] << endl;
  return 0;
}
