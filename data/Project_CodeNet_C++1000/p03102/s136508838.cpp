#include <iostream>
using namespace std;

int main()
{
  int N, M, C, A[21][21], B[21];
  cin >> N >> M >> C;
  for(int i = 0; i < M; ++i) cin >> B[i];
  for(int i = 0; i < N; ++i)
  {
    for(int j = 0; j < M; ++j)
    {
      cin >> A[i][j];
    }
  }

  int solved = 0;
  for(int i = 0; i < N; ++i)
  {
    int score = 0;
    for(int j = 0; j < M; ++j)
    {
      score += A[i][j] * B[j];
    }
    score += C;
    if(score > 0) solved++;
  }
  
  cout << solved << endl;
}