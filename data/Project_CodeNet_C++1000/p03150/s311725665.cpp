#include <iostream>
using namespace std;

int main(void){
  string s, tgt="keyence";
  int pref[8], suff[8];
  int ans;
  
  cin >> s;
  if (s.length()<tgt.length()){
    cout << "NO" << endl;
    return 0;
  }
  // check prefix and suffix
  pref[0] = suff[0] = 1;
  for (int i=0; i<tgt.length(); i++){
    pref[i+1] = pref[i] & (s[i]==tgt[i]);
    suff[i+1] = suff[i] & (s[s.length()-1-i]==tgt[tgt.length()-1-i]);
  }
  ans = 0;
  for (int i=0; i<8; i++){
    ans |= pref[i]&&suff[7-i];
  }
  cout << (ans?"YES":"NO") << endl;
  return 0;
}
