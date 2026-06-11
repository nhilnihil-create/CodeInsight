#include <iostream>
#include <string>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  double Y = 0;
  for(int i = 0;i < N;i++){
    double x;
    string u;
    cin >> x >> u;
    
    if(u == "JPY") Y += x;
    if(u == "BTC") Y += x * 380000.0;
  }
  
  cout << Y << endl;
  
  return 0;
}