#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int k = s.length();
  int cnt = 0;
  for(int i = 0; i < k; i++){
    if(s[i] == 'o') cnt++;
  }
  if(8-cnt <= 15-k) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}