#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int nu1,nu2,nu3,nu4;
  nu1=n/1000;
  nu2=n/100-nu1*10;
  nu4=n%10;
  nu3=(n%100-nu4)/10;
  if((nu1 == nu2 && nu2 == nu3) || (nu2 == nu3 && nu3 == nu4)){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}