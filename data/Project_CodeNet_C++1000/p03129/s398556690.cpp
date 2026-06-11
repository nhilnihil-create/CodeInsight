#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin >> a >> b;
  
  if(((a/2)+(a%2))< b){
    cout << "NO" << endl;
  }
  
  else{
    cout << "YES" << endl;
  }
}