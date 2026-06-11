#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }

  int max = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (i != j && max < abs(A.at(i) - A.at(j))){
        max = abs(A.at(i) - A.at(j));
      }
    }
    
  }

  cout << max << endl;
  
  
}