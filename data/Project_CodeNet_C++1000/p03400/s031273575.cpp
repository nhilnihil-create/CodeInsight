#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N, D, X;
  cin >> N >> D >> X;

  vector<int> A(N);

  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  
  int eaten = 0;

  for (int i = 0; i < D; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (A.at(j) * i + 1 <= D){
        eaten += 1;
      }
    }
    
  }
  cout << X + eaten << endl;
}