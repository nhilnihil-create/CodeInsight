#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d ;
  bool q = true;
if(abs(a-c) >d){
  if(abs(a-b)>d|| abs(b-c) >d){
    q = false;
  }
}

  if(q ==true)cout << "Yes" << endl;
  else cout << "No" << endl;
}

