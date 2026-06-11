#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,d,east;
  cin >> a >> b;
  d = b - a;
  east = d *(d+1) /2;
  cout << east - b <<endl;  
}
