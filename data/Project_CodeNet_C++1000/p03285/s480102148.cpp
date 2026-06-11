#include <iostream>
using namespace std;

int main(){
  int i, n;
  cin >> n;
  
  for( i=0; i<=n/7; i++ ){
    if( (n-7*i)%4==0 ){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}