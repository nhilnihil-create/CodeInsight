#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B;
  cin >> A >> B;
  int ans = 0;
  
  for (int i = A; i <= B; i++){
    vector<int> dig(5);
    int tempi = i;
    for (int j=0; j<5; j++){
      dig.at(j) = tempi%10;
      tempi /= 10;
    }
    if(dig.at(0) == dig.at(4) && dig.at(1) == dig.at(3)) ans++;
  }
  cout << ans << endl; 
  
} 
