#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a = 0, b = 0, c = 0, d = 0;
  for(int i = 0; i < n; i++){
    char p;
    cin >> p;
    if(p == 'W') a = 1;
    if(p == 'P') b = 1;
    if(p == 'G') c = 1;
    if(p == 'Y') d = 1;
  }
  if(a + b + c + d == 4) cout << "Four" << endl;
  else cout << "Three" << endl;
}