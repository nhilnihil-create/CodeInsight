#include<bits/stdc++.h>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(){
  string s; cin >> s;
  int n = s.size();
  int cnt = 0;
  for(int i=0; i<n; i++) if(s[i] == 'o') cnt++;
  for(int i=n; i<15; i++) cnt++;
  if(cnt >= 8) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
