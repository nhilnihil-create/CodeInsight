#include <bits/stdc++.h>
using namespace std;

int main(){
  int a , b , c , d;
  cin >> a >> b >> c >> d;
  int an = max(a , b) - min(a , b);
  int sw = max(b , c) - min(b , c);
  int er = max(a , c) - min(a , c);
  if( an <= d && sw <= d){
    cout << "Yes" << endl;
  }
  else if(er <= d){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
