#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void){
  int n,i,a,ex=1,all=1;
  
  cin >> n;
  for (i=0;i<n;i++){
    cin >> a;
    all*=3;
    if (a%2==0) ex*=2;
  }
  
  cout << all-ex << endl;
  
  return 0;
}