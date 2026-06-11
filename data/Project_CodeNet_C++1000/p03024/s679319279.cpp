#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
  string s; int cnt = 0;
  cin >> s;
  for(int i=0;i<s.size();i++) if(s[i] == 'o') cnt++;
  if(cnt+(15-s.size()) >= 8) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}