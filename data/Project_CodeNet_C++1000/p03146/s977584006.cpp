#include <bits/stdc++.h>
using namespace std;

int main() {
  int s;
  cin>>s;
  vector<bool>check(100000000);
  check[s]=true;
  int i=1;
  while(1){
    i++;
    if(s%2==0) s/=2;
    else s=3*s+1;
    if(check[s]){
      cout<<i<<endl;
      break;
    }
    else{
      check[s]=true;
    }
  }
}
