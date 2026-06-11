#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,r = 0,b = 0;
  cin >> n;
  char s[n];
  for(int i=0;i<n;i++){
    cin >> s[i];
  }
  for(int i=0;i<n;i++){
    if(s[i] == 'B')b += 1;
    else r += 1;
  }
  if(r > b)cout << "Yes" << endl;
  else cout << "No" << endl;
}