#include <bits/stdc++.h>
using namespace std;

int main(){
  int R;
  cin >> R;

  string ans= (R < 1200) ? "ABC"
             :(R < 2800) ? "ARC"
                         : "AGC";
  cout << ans << endl;
}