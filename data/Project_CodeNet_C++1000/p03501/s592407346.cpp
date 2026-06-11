#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,a,b;
  cin >> n >> a >> b;
  int money1;
  int money2;
  money1 = n*a;
  money2 = b;
  if(money1>money2){
    cout << money2 <<endl;
  }
  else
   cout << money1 << endl;
  return 0;
}
