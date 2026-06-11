#include <bits/stdc++.h>
using namespace std;
int main(){
  int a;
  cin >> a;
  if(a==111)
    cout << 3 << endl;
  else if(a==1 || a==10 || a==100)
    cout << 1 << endl;
  else if(a==110 || a==11 || a==101)
    cout << 2 <<endl;
  else
    cout << 0 << endl;
}
