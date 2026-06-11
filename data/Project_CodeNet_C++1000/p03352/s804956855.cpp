#include <bits/stdc++.h>
using namespace std;

int main() {
  int X;
  cin >> X;
  int ans=1;
  int exp;
  
  for(int i=2; i*i<=X; i++){
    exp=i*i;
    while(exp<=X){
      if(exp>ans)ans=exp;
      exp*=i;
    }
  }
  
  cout << ans << endl;
}