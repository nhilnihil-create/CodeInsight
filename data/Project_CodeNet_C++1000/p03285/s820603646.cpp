#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int count = 0;
  for(int i = 0; i < 100; i++){
    for(int j = 0; j < 100; j++){
      if(N == 4*i + 7*j){
        count++;
      }
    }
  }
  string ans;
  if(count != 0){
    ans = "Yes";
  }else{
    ans = "No";
  }
  cout << ans << endl;
}