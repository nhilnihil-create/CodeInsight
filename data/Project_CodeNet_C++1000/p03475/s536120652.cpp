#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
int C[500], S[500], F[500];
int res[500];

int main(int argc, char* argv[]) {
  cin >> N;
  for (int i = 0; i < N - 1; i++)
    cin >> C[i] >> S[i] >> F[i];

  for (int i = 0; i < N; i++) {
    int time = 0;
    for (int j = i; j < N - 1; j++) {
      if (time < S[j]) {
        time = S[j] + C[j];
      } else if (time % F[j] == 0) {
        time += C[j];
      } else {
        time += C[j] + F[j] - time % F[j];
      }
    }
    cout << time << endl;
  }

  return 0;
}