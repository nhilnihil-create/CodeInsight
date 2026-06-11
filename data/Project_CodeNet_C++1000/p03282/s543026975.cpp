#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  long long k;
  cin >> s >> k;
  
  char ans = '1';
  int l = s.size();
  for(int i = 0; i < l; i++){
    ans = s.at(i);
    if(ans != '1') break;
    if(i == k-1) break;
  }
  
  cout << ans << endl;
}