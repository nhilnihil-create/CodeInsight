
/* Preprocess */
#include <bits/stdc++.h>

#define pow(n) (n)*(n)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()


/* Field */
using namespace std;

/* Function */

int main (void) 
{

  /* Variable_Proclamation */
  int now_rate;     // input R
  int target_rate;  // input G
  int per;          // output performance


  /* Input, Initialize */
  cin >> now_rate;
  cin >> target_rate;


  /* Calculation */
  // 計算式は方程式の変形で導出
  per = target_rate *2 - now_rate;


  /* Output */
  cout << per << endl;


  return 0;

}


