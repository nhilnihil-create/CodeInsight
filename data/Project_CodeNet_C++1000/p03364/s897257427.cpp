#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  string s[309];
  cin >> n;
  for(int i=0;i<n;i++)cin >> s[i];
  int cnt=0;
  for(int k=0;k<n;k++){
    bool is_sym=true;
    for(int i=0;i<n&&is_sym;i++){
      for(int j=1;j<n-i&&is_sym;j++){
        if(s[(i+k+j)%n][(i)%n]!=s[(i+k)%n][(i+j)%n])is_sym=false;
      }
    }
    if(is_sym)cnt++;
  }
  cout << cnt*n << endl;
}

