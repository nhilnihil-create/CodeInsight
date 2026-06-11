
/* include */
#include <bits/stdc++.h>

#define pow(n) (n)*(n)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

/* function */
//  - none - 


/* code */
int main (void) 
{

  /* Variable_Proclamation */
  int N;    // input
  int A, B;    // input
  string ans;  // output

  int left_end, right_end;


  /* Input, Array_Proclamation */
  cin >> N;
  cin >> A >> B;


  /* Initialize */
  left_end  = 1;
  right_end = N;


  /* Calculation */
  while(true)
  {

    if(A+1 == B && A == left_end)
    {
      ans = "Borys";
      break;
    }
    else if(A+1 == B)
    {
      A--;
    }
    else
    {
      A++;
    }
    
    if(A == B-1 && B == right_end)
    {
      ans = "Alice";
      break;
    }
    else if(A == B-1)
    {
      B++;
    }
    else
    {
      B--;
    }

  }


  /* Output */
  cout << ans << endl;


  return 0;

}


/* entity */
//  - none -


