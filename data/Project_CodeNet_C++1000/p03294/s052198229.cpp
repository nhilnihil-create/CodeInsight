#include<iostream>
using namespace std;
int main(){
  int a,ans,b=0;
  cin >> a;
  for(int i=0;i<a;i++) {
    cin >> ans;
    b += ans-1;
  }
  cout << b;
}