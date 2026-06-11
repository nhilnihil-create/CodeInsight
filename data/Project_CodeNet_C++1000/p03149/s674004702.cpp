#include <bits/stdc++.h>
using namespace std;

vector<int> v(4,0);

int main(){
  for(auto &p: v)cin >> p;
  sort(v.begin(),v.end());
  if(v[0] == 1 && v[1] == 4 && v[2] == 7 && v[3] == 9)cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
