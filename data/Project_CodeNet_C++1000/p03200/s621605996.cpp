# include <iostream>
using namespace std;

int main(){
  string s;
  cin >> s;

  typedef long long ll;
  ll ans = 0;
  int cur = 0;
  for(int i=0; i<s.size(); i++){
    if(s[i] == 'B') cur++;
    else ans += cur;
  }

  cout << ans << endl;
  return 0;
}