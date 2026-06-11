#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N, N_;
  int sum = 0;
  
  cin >> N;
  N_ = N;
  while (true)
  {
    if (N_ == 0)
    {
      break;
    }
    sum += N_ % 10;
    N_ /= 10;
  }
  if (N % sum == 0)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}
