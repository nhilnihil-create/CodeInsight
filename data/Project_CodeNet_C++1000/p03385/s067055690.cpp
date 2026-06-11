#include <bits/stdc++.h>
using namespace std;

int main(){
  int ans=0;
  for(int i=0;i<3;i++){
    char s;
    cin >> s;
    if(s=='a') ans+=100;
    else if(s=='b') ans+=10;
    else ans++;
  }
  if(ans==111) cout << "Yes" << endl;
  else cout << "No" << endl;
}