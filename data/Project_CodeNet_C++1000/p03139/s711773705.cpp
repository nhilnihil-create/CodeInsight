#include<iostream>
using namespace std;

int main(){
  int n,a,b;
  cin >> n >> a >> b;
  cout << min(a,b) << endl;
  if(n>=a+b) cout << 0 << endl;
  else cout << a+b-n << endl;

  return 0;
}