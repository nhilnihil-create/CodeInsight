#include <bits/stdc++.h>
using namespace std;


int main()
{
  int N, T, A;
  
  cin >> N >> T >> A;
  
  int ans;
  double t = 1000;
  for (int i = 0; i < N; i++)
  {
    int x;
    cin >> x;

    if (t > abs(A - (T - x * 0.006)))
    {
      t = abs(A - (T - x * 0.006));
      ans = i+1;
    }
    
  }
  cout << ans << endl;
}
