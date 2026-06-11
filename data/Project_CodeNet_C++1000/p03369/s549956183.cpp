#include <bits/stdc++.h>
using namespace std;

int main(){
  int ans=7;
  for(int i=0;i<3;i++){
    char s;
    cin >> s;
    if(s=='o') ans++;
  }
  cout << 100*ans << endl;
}