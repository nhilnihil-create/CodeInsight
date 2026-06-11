#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long Total = 0;
  int N, A[100000];
  
  cin >> N;
    
  for(int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  
  for(int i = 0; i < N; i++)
  {
    Total += A[i] -1;
  }
  
  cout << Total;
}