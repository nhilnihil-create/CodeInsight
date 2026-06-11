#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  string s;
  cin >> n >> s;
  int r = 0, b = 0;
  for(int i = 0; i < n; i++){
    if(s[i] == 'R') r++;
    else b++;
  }
  if(r > b) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}