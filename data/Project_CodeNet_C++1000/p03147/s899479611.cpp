#include <iostream>

using namespace std;

int main(){
  int N, h[100], count = 0;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> h[i];
  
  int n = 0;
  while (n < N)
  {
    if (h[n] != 0)
    {
      for (int i = n; i < N; i++)
      {
        if (h[i] == 0) break;
        h[i]--;
      }
      //for (int i = 0; i < N; i++) cout << h[i] << " ";
      //cout << endl;
      count++;
    }
    else n++;
  }
  cout << count;
}