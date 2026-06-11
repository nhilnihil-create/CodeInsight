#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  for(int i=0; i<n; ++i) cin >> s[i];
  int ans = 0;
  for(int i=0; i<n; ++i){
    bool ansis = true;
    for(int j=0; j<n; ++j) for(int k=j+1; k<n; ++k){
      if(s[(j+i)%n][k] != s[(k+i)%n][j]) ansis = false;
    }
    if(ansis) ans += n;
  }
  cout << ans << endl;
}