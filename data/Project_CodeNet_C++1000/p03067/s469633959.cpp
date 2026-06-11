#include <iostream>
using namespace std;

int main(){
  int A, B, C;
  cin >> A >> B >> C;
  
  string result = ((A < C && C < B) || (A > C && C > B)) ? "Yes" : "No";
  cout << result;
  return 0;
}