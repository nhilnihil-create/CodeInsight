#include <iostream>
using namespace std;

int main(){
  int a;
  cin >> a;
  if((a/10)%111==0)cout << "Yes";
  else if((a%1000)%111==0)cout << "Yes";
  else cout << "No";
}
