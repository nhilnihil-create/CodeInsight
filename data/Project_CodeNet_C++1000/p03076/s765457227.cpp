#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> price(5);
  for(int i = 0; i < 5; i++){
    cin >> price.at(i);
  }
  int index = 0, tmp, saisho = 10;
  for(int i = 0; i < 5; i++){
    if (0 < (price.at(i) % 10) && (price.at(i) % 10) < saisho){
      index = i;
      saisho = price.at(i) % 10;
    }
  }
  int ans = 0;
  for(int i = 0; i < 5; i++){
    if(i == index) ans+= price.at(i);
    else if(price.at(i) % 10 == 0) ans+= price.at(i);
    else ans += price.at(i) + (10 - price.at(i) % 10);
  }
  cout << ans << endl;
  return 0;
}