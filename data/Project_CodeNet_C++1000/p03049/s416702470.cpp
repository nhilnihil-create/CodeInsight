#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int Bstart = 0, Aend = 0, BandA = 0;
  int ans = 0;
  for(int i=0; i<n; ++i){
    string s;
    cin >> s;
    if(s[0] == 'B' && s[s.size()-1] == 'A') ++BandA;
    else if(s[0] == 'B') ++Bstart;
    else if(s[s.size()-1] == 'A') ++Aend;
    
    for(int i=0; i<s.size()-1; ++i){
      if(s[i] == 'A' && s[i+1] == 'B') ++ans;
    }
  }
  ans += min(Aend + BandA, BandA + Bstart);
  if(Aend == 0 && Bstart == 0 && BandA != 0) --ans;
  cout << ans << endl;
}