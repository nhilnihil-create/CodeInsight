#include <bits/stdc++.h>
using namespace std;

int main(){
  string a;
  int ans = 0;
  cin >> a;
  int a_len = a.size();
  for(int i = 0; i < a_len; i++){
    if(a[i] == '1'){
      ans++;
    }else{
      continue;
    }
  }
  cout << ans << endl;
}
