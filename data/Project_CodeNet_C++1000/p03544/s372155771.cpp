#include <bits/stdc++.h>
using namespace std;

int main(){

  int N;
  cin >> N;

  int64_t L_b1,L_b2,L;

  if (N == 0)
  {
    L = 2;
  }
  else if (N ==1)
  {
    L = 1;
  }
  else
  {
    L_b1 = 1;
    L_b2 = 2;
    for (int i = 1; i<N; i++)
    {
      L = L_b2 + L_b1;
      L_b2 = L_b1;
      L_b1 = L;
    }
  }
  cout << L << endl;
}