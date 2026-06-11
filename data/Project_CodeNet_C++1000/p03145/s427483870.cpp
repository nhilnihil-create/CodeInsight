#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c ;
  int d=max(a,max(b,c));
  if(d==a){
    cout << b*c/2 << endl;
  }
  if(d==b){
    cout << a*c/2 << endl;
  }
  if(d==c){
    cout << a*b/2 << endl;
  }
}
