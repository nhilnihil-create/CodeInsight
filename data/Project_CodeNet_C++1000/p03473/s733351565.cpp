
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
  int M;      // input
  int grace;  // input （猶予）


  /* Input, Initialize */
  cin >> M;
  grace = 24*2; // two days


  /* Calculation */
  grace = grace - M;


  /* Output */
  cout << grace << endl;


  return 0;

}


