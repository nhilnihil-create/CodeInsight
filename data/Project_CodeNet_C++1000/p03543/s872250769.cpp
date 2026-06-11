#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  int a,b,c,d;
  cin >> n;
  a = n  % 10;
  n = n/10;
  b = n% 10;
  n = n/10;
  c = n %10;
  n /= 10;
  d = n ;
  if(a==b&&b==c){
    cout << "Yes"<< endl;
  }
  else if(b==c&&c==d){
    cout << "Yes" << endl;
  }
  else cout << "No"<< endl;
  return 0;
}
