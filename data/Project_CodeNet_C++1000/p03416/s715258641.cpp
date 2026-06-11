#include <bits/stdc++.h>
using namespace std;

int main() {
 
  int A,B;
  cin >> A >> B;
  
  vector<int> N(5);
  
  int ans=0;
  for(int i=A; i<B+1; i++){
    int t=i;
    for(int j=0; j<5; j++){
      N.at(j) = t % 10;
      t/=10;
    }
    
    if(N.at(0) == N.at(4) && N.at(1) == N.at(3)){
      ans++;
    }
  }
  
 cout << ans << endl;
  
}
