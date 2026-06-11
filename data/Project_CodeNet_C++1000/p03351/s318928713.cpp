#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,diff;
  cin >> a >> b >> c >> diff;

  string ans= (abs(c-a) <= diff || (abs(b-a) <= diff && abs(c-b) <= diff)) ? "Yes" : "No";

  cout << ans << endl;
}