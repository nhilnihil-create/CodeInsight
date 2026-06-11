#include <iostream>
#define ll long long
using namespace std;

int main() {
  string s;
  cin >> s;

  int f = s.length();
  int cntr = 0;
  
  ll ans = 0;
  for (int i = 0; i <= f-1; i++){
    if (s[i] == 'B')
      cntr++;
    else{
      ans = ans + cntr;
    }
  }
  cout << ans << endl;
}