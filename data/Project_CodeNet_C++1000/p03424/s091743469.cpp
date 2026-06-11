#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  string ans = "Three";
  for(int i = 0; i < N; i++){
    string col;
    cin >> col;
    if(col == "Y"){
      ans = "Four";
    }
  }
  cout << ans << endl;
  return 0;
}