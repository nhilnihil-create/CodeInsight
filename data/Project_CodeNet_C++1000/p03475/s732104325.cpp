#include <iostream>
#include <vector>
using namespace std;
int main(void) {
  int N;
  cin >> N;
  vector <int> C(N), S(N), F(N);
  for (int i = 1; i < N; i++) {
    cin >> C[i] >> S[i] >> F[i];
  }

  for (int stpos = 1; stpos < N; stpos++) {
    int now = 0;
    for (int i = stpos; i < N; i++) {
      if (now < S[i]) now = S[i];
      if ((now % F[i]) != 0) {
        now = (now+F[i])/F[i] * F[i];
      }
      now += C[i];
    }
    cout << now << endl;
  }
  // 最後の駅
  cout << 0 << endl;
  return 0;
}
