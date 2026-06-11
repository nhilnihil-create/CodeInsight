#include <iostream>
using namespace std;

int main(){
  int N, L[10];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> L[i];
  
  int max = 0;
  int sum = 0;
  for (int i = 0; i < N; i++)
  {
    sum += L[i];
    if (max < L[i]) max = L[i];
  }
  sum -= max;
  
  if (max < sum) cout << "Yes";
  else cout << "No";
}