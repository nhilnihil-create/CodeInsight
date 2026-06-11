#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
  int N, M;
  int L[100000], R[100000];
  
  
  cin >> N >> M;
  
  int min = 0;
  int max = N;
  
  for(int i = 0; i < M; i++)
  {
    cin >> L[i] >> R[i];
    
    if (L[i] > min) min = L[i];
    if (R[i] < max) max = R[i];
  }
  
  int total = 0;
  
  //cout << max << ' ' << min << endl;
  
  if ((max - min) >= 0) 
  {
    total = (max - min) + 1;
  }
  
  cout << total << endl;
}