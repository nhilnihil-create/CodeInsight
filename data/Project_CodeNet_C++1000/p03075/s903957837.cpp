#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d,e,k;
  cin >> a >> b >> c >> d >> e >> k;
  bool A= false;
  if(e-a<=k){
    A=true;
  }
  if(A){
    cout << "Yay!" << endl;
  }
  else{
    cout << ":(" << endl;
  }
}