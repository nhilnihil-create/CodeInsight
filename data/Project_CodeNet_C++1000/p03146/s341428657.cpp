#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  int S;
  cin >> S;
  
  vector<bool> passed(1000000, false);
  passed.at(S) = true;
  int ans = 1;
  while (true){
    if (S % 2 == 0){
      S /= 2;
    }
    else{
      S = 3 * S + 1;
    }
    ans++;
    
    if (passed.at(S) == true){
      break;
    }
    
    passed.at(S) = true;
    
  }
  
  cout << ans << endl;
    
}