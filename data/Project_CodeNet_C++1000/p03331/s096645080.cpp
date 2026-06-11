#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >>n;
  int kotae=0;
  while(n){
    kotae+=n%10;
    n/=10;
  }
  if(kotae==1)cout<<10<<endl;
  else cout<<kotae<<endl;
}