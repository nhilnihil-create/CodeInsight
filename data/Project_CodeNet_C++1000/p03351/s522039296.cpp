#include<iostream>
using namespace std ;

int main(){
  int a,b,c,d ;
  cin >> a >> b >> c >> d ;
  if(-1*d<=a-b&&a-b<=d&&-1*d<=b-c&&b-c<=d) cout << "Yes" << endl ;
  else if(-1*d<=a-c&&a-c<=d) cout << "Yes" << endl ;
  else cout << "No" << endl ;
}
