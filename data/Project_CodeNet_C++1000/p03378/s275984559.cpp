#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N, M, X;
  cin >> N >> M >> X;

  vector<int> A(M);

  for (int i = 0; i < M; i++)
  {
    cin >> A.at(i);
  }
  

  int left = 0;
  int right = 0;

  for (int i = 0; i < M; i++)
  {
    if (A.at(i) < X)
    {
      left += 1;
    }
    else
    {
      right += 1;
    }
    
    
  }
  
  
  cout << min(left, right) << endl;
}