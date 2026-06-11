#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  vector<int> c(n);
  for(int i = 0; i < n; i++){
    cin >> v.at(i);
  }
  for(int i = 0; i < n; i++){
    cin >> c.at(i);
  }
  
  int value = 0;
  int ans = 0;
  
  for(int bit = 0; bit < (1<<n); ++bit){
    for(int i = 0; i < n; i++){
      if(bit & (1 << i)){
        ans = ans + v.at(i) - c.at(i);
      }
    }
    if(ans > value){
      value = ans;
    }
    ans = 0;
  }
   cout << value << endl;
}
      
    