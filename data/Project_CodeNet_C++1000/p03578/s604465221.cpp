#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
  int N, M;
  cin >> N;

  map<long long, int> m;
  for (int i = 0; i < N; ++i) {
    long long d;
    cin >> d;
    if (m.find(d) == m.end())
      m[d] = 0;
    ++m[d];
  }

  cin >> M;

  long long t[M];
  for (int i = 0; i < M; ++i)
    cin >> t[i];

  for (int i = 0; i < M; ++i) {
    if (m.find(t[i]) == m.end() || m[t[i]] == 0) {
      cout << "NO" << endl;
      return 0;
    } else {
      --m[t[i]];
    }
  }

  cout << "YES" << endl;

  return 0;
}