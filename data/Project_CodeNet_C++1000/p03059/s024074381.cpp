#include <iostream>

using namespace std;

int main()
{
  int A, B, T, cost, num;

  cin >> A >> B >> T;
  int i =0;
  i +=A;
  
  while(i<(T+0.5)){
    i +=A;
    num +=B;
  }

  cout << num <<endl;

  return 0;
}