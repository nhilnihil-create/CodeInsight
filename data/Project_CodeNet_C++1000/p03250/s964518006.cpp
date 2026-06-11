#include <iostream>
#include <string>
using namespace std;

int main()
{
  int A, B, C;
  cin >> A >> B >> C;
  
  int max = A;
  if(max < B)
  {
    max = B;
  }
  if(max < C)
  {
    max = C;
  }
  
  cout << max * 10 + (A+B+C-max) << endl;
  
  return 0;
}