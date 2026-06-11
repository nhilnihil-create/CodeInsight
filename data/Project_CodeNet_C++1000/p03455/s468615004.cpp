
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
  int a, b;   // input 基本料金
  string ans; // output

  int pro; // product（積）
  int sur; // surplus（剰余）


  /* Variable_Proclamation */
  cin >> a >> b;


  /* Calculation */
  pro = a * b;
  sur = pro % 2;

  if(sur == 1)
  {
    ans = "Odd";
  }
  else if(sur == 0)
  {
    ans = "Even";
  }


  /* Output */
  cout << ans << endl;


  return 0;

}
