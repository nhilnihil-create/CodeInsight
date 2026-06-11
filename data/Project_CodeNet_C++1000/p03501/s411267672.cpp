#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,N,b=0;
  cin >> a >> N >> b;
  if(a*N < b)
    cout << a*N << endl;
  else
    cout << b << endl;
  return 0;
}