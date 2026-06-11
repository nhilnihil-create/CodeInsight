#include <iostream>

using namespace std;

int main(){
  int a, b, t;
  cin >> a >> b >> t;
  
  int result = 0;
  for(int i = a; i < t + 0.5; i += a){
    result += b;
  }
  cout << result << endl;
}