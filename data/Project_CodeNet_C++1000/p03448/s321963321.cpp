#include <bits/stdc++.h>
using namespace std;

int main() {
  // 科目の数Nを受け取る
  int A, B, C, X;
  cin >> A >> B >> C >> X;

  int count(0);
  for(int na = 0; na <= A; na++)
  {
    const int resA = X - 500 * na; 
    for(int nb = 0; nb <= B; nb++)
    {
      const int res = resA - 100 * nb;
      if( res % 50 == 0 && res / 50 <= C)
      {
         count++;
      }
      if( res < 100 )
      {
        break; 
      }        
    }
    if( resA < 500 )
    {
      break; 
    }
  }
  cout << count << endl;  
}
