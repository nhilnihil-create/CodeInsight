
/* Preprocess */
#include <bits/stdc++.h>

/* Field */
using namespace std;

/* Function */
int main (void) 
{

  string S;  // input
  
  int i;
  int count; // 'o'と書かれている個数
  int ans;


  cin >> S;


  count = 0;

  // 3回ループくらいならwhile不要(?)
  if( S.at(0) == 'o' )
  {
    count++;
  }

  if( S.at(1) == 'o' )
  {
    count++;
  }

  if( S.at(2) == 'o' )
  {
    count++;
  }

  // i = 0;
  // while( i < 3 )
  // {

  //   if( place.at(i) == '1' )
  //   {
  //     count++;
  //   }

  //   i++;

  // }


  ans = 700 + 100 * count;

  cout << ans << endl;


  return 0;

}
