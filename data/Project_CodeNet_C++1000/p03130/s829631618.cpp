#include <bits/stdc++.h>

using namespace std;

int main(){
  int array[4] = {0,0,0,0};
  string ans = "YES";
  for(int i = 0; i < 6 ; i++){
    int t = 0;
    cin >> t;
    array[t-1] += 1;
  }
  for(int i = 0; i < 4 ;i ++){
    if(array[i] > 2){
      ans = "NO";
    }
  }
  cout << ans << endl;

}
