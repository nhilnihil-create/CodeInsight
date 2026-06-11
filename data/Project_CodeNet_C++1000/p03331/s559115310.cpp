#include <bits/stdc++.h>

using namespace std;

int Sum_AllDigits (int);

int main (void) 
{

  /* Variable_Proclamation */
  int N;    // input
  int min;  // output

  int i;    // subscript
  int A, B;
  int A_sda, B_sda;
  int sum_sda;


  /* Input, Array_Proclamation */
  cin >> N;


  /* Initialize */
  min = INT_MAX;


  /* Calculation */
  for(i=1; i<=N/2; i++)
  {

    A = i;
    B = N -i;

    A_sda = Sum_AllDigits(A);
    B_sda = Sum_AllDigits(B);

    sum_sda = A_sda + B_sda;
    // cout << endl;
    // cout << sum_sda << endl;

    if(min > sum_sda)
    {
      min = sum_sda;
    }

  }
  

  /* Output */
  cout << min << endl;


  return 0;

}

int Sum_AllDigits (int n)
{

  int sum;

  sum = 0;
  while(n > 0)
  {
    sum += n %10;
    n   /= 10;
  }

  return sum;

}

