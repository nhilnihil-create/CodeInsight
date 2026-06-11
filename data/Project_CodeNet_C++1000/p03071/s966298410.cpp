#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  
  int x=max(a+a-1,b+b-1);
  
  cout << max(x,a+b) << endl;
}