#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  int N;
  cin >> N;

  int C[N - 1];
  int S[N - 1];
  int F[N - 1];
  for (int i = 0; i < N - 1; ++i)
    cin >> C[i] >> S[i] >> F[i];

  for (int i = 0; i < N - 1; ++i) {
    long long t = S[i];
    for (int j = i; j < N - 1; ++j) {
      if (t < S[j]) {
        t = S[j];
      }
      if ((t - S[j]) % F[j] != 0)
        t += F[j] - ((t - S[j]) % F[j]);
      t += C[j];
    }
    cout << t << endl;
  }

  cout << 0 << endl;

  return 0;
}