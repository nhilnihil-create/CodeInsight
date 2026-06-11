#include <iostream>
using namespace std;

int main()
{
  int A, B, C, X;
  int count=0;
  int resA,resB,resC;

  cin >> A;
  cin >> B;
  cin >> C;
  cin >> X;

  for (int i = 0; i < A+1; i++)
  {
    resA = X - 500*i;
    if(resA == 0){
      count++;
      continue;
    }
    for (int j = 0; j < B+1; j++)
    {
      resB = resA - 100*j;
      if(resB == 0){
        count++;
        continue;
      }
      for (int k = 0; k < C+1; k++)
      {
        resC = resB - 50*k;
        if(resC == 0){
          count++;
          continue;
        }
      }
    }
  }
  cout << count << endl;

  return 0;
}