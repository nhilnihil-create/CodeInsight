#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i > 0; i++)

using ll=long long;
string s;
bool ans = 1;

int main(){
  cin >> s;
  string sl = s.substr(0, 7);
  string sr = s.substr(s.size()-7,7);
  string sample = "keyence";
  for(int i = 0; i < 7; i++){
    if(sl[i] != sample[i] && sr[i] != sample[i]) ans = 0;
  }
  cout << ((ans) ?"YES" :"NO") << endl;
}