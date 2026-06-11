
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
  int A, B;   // input
  int C, D;   // input
  string ans; // output

  int left_dish, right_dish;


  /* Input, Initialize */
  cin >> A >> B;
  cin >> C >> D;


  /* Calculation */
  left_dish  = A + B;
  right_dish = C + D;

  if(left_dish > right_dish)
  {
    ans = "Left";
  }
  else if(left_dish < right_dish)
  {
    ans = "Right";
  }
  else if(left_dish == right_dish)
  {
    ans = "Balanced";
  }


  /* Output */
  cout << ans << endl;


  return 0;

}


