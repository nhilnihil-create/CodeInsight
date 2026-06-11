#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,aa,bb;
  cin >> a >> b;
  aa = a%2;
  bb = b%2;
  if (aa==0||bb==0){
    cout << "Even" << endl;
  }
  else{
    cout << "Odd" << endl;
  }
}