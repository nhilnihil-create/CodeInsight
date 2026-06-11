#include <iostream>
using namespace std;
int main(){
  int a,b,count=0;
  for(int i=0;i<2;i++){
    cin >> a >> b;
    count += min(a,b);
  }
  cout << count;
  return 0;
}
