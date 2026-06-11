#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<int> v;
  for(int i = 0; i < 4; i++){
    int x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  if(v[0] == 1 && v[1] == 4 && v[2] == 7 && v[3] == 9)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;  
  return 0;
}