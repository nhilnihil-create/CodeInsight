#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int a;
  cin >> a;
  if(a%2==0) cout << a*a/4;
  else cout << a/2 * (a-a/2);
}
