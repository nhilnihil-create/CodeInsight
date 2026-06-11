#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b; 
  cin >> a >> b;
  
  int ans=0;
  for(int i=a; i<=b; i++){
    string temp = to_string(i);
    if(temp[0]==temp[4] && temp[1]==temp[3]) ans++;
  }
  cout << ans << endl;
}