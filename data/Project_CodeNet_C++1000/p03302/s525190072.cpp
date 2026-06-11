#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b;
  cin >> a>>b;
  if(a+b==15){
    cout << "+"<<endl;
    return 0;
  }
  cout << (a*b==15?"*":"x")<<endl;
}