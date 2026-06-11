#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int> v(4);
  for(auto&e:v)cin >> e;
  sort(v.begin(),v.end());
  if(v[0] == 1 && v[1] == 4 && v[2] == 7 && v[3] == 9)
    cout << "YES" << endl;
  else 
    cout << "NO" << endl;
}