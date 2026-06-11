#include <iostream>

using namespace std;

int main(){
  int a, b, c, count = 0;
  cin >> a >> b >> c;
  if(a>b)
    count = 0;
  else if(a==b)
    count = 1;
  else{
    if(b>=(a*c))
      count = c;
    else
      count = b/a;
  }
  cout << count << endl;
  return 0;
}
