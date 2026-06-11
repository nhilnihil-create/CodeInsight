#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MX = 100001;

int main(){
  string s;
  cin >> s;

  int ans = 0;
  for(char c : s){
    if(c=='1') ans++;
  }

  cout << ans << endl;
  
  return 0;
}