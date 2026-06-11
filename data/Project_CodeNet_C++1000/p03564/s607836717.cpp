#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, r;
  
  r = 1;
  cin >> N >> K;
  
  for (int i = 0; i < N; i++)
  {
    if( r + K < 2 * r)
    {
      r = r + K;
    }
    else
    {
      r *= 2;
    }
  }
  cout << r << endl;

}
