#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, a, b;  cin >> n >> a >> b;

  string ans = "Alice";
  if(abs(b-a)%2 == 1)  ans = "Borys";

  cout << ans << endl;


  return 0;
}
