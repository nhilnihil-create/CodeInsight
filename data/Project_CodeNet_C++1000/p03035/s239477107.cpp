#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin >> a >> b;
  int fee=0;
  if(a>=13) fee=b;
  if(a<=12 && a>=6) fee=b/2;
  cout << fee << endl;
  return 0;
}