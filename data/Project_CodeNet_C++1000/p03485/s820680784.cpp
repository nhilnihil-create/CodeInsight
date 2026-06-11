#include <bits/stdc++.h>
using namespace std;

int main(){
  int p,q;
  cin >>p>>q;
  if((p+q)%2==0){
  cout << (p+q) / 2<< endl;
  }
  else{
  cout << (p+q+1) / 2 << endl;
  }
}