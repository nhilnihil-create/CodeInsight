#include <iostream>
using namespace std;
int main()
{
  int N, M;
  cin >> N >> M;
  int *like = new int[M+1];
  
  for (int i = 0; i <= M; i++) like[i] = 0;
  for (int i = 0; i < N; i++) {
    int K;
    cin >> K;
    for (int j = 0; j < K; j++) {
      int A;
      cin >> A;
      like[A]++;
    }
  }
  int ans = 0;
  for (int i = 1; i <= M; i++) {
    if (like[i]==N) ans++;
  }
  cout << ans << endl;
  return 0;
}
