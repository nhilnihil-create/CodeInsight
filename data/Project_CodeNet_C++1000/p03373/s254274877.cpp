
/* include */
#include <bits/stdc++.h>

#define pow(n) (n)*(n)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

/* function */



/* code */
int main (void) 
{

  /* Variable_Proclamation */
  int A, B, C;    // input
  int X, Y;    // input

  int high_dem, low_dem;
  int start_cost;
  int rem, rem_cost;
  int total_fee;

  /* Input, Array_Proclamation */
  cin >> A >> B >> C;
  cin >> X >> Y;


  /* Initialize */
  total_fee = 0;



  /* Calculation */  
  start_cost = min(A+B, C*2);

  if(X > Y)
  {
    high_dem = X;
    low_dem  = Y;
    rem_cost = min(A, C*2);
  }
  else if(X <= Y)
  {
    high_dem = Y;
    low_dem  = X;
    rem_cost = min(B, C*2);
  }
  

  total_fee += start_cost * low_dem;

  rem        = high_dem - low_dem;
  total_fee += rem_cost * rem;



  /* Output */
  cout << total_fee << endl;


  return 0;

}


/* entity */

