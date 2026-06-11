#include <bits/stdc++.h>
using namespace std;

int main(){
  // input
  int N, i, k = 0, n = 2;
  bool div = true;
  cin >> N;
  int A[N];
  for ( i = 0; i < N; i++)
  {
    cin >> A[i];
  }

  //manipulate
  while (div)
  {
    for ( i = 0; i < N; i++)
    {
      if (A[i] % n != 0)
      {
        div = false;
        break;
      }
    }
    if (div)
    {
      k++;
      n *= 2;
    }else
    {
      break;
    }
  }

  cout << k << endl;
}
