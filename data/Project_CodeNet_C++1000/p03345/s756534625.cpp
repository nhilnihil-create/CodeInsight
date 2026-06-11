#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  long long int k;
  cin >> a >> b >> c >> k;
  if(k%2==0){
    if(a-b>pow(10,18)){
      cout << "Unfair" << endl;
    }
    else cout << a-b << endl;
  }
  else{
    if(b-a>pow(10,18)){
      cout << "Unfair" << endl;
    }
    else cout << b-a << endl;
  }
  return 0;
}