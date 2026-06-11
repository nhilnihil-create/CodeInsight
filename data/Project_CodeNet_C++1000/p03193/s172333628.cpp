#include <iostream>
using namespace std;
int main()
{
  int N, H, W;
  cin >> N >> H >> W;
  int A[N], B[N];
  for (int i = 0; i < N; i++)
    cin >> A[i] >> B[i];
  int ans = 0;
  for (int i = 0; i < N; i++)
  {
    if (H <= A[i] && W <= B[i])
      ans++;
  }
  cout << ans << endl;
  return 0;
}