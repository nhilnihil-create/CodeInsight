#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,A0,B0;
  cin >> N >> A0 >> B0;
  
  string ans= ((A0- B0)%2==0) ? "Alice"
                              : "Borys";

  cout << ans << endl;
}