#include<iostream>
#include<map>
using namespace std;

int N, M;
int A[100010], B[100010], C[100010];

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int j = 0; j < M; j++) cin >> B[j] >> C[j];
  map<int, long> S;
  for (int i = 0; i < N; i++) S[A[i]]++;
  for (int j = 0; j < M; j++) S[C[j]] += B[j];
  long count = 0; long sum = 0;
  for (auto it = S.rbegin(); it != S.rend(); it++) {
    if (count + it->second >= N) {
      sum += (long)(it->first) * (N - count);
      break;
    } else {
      sum += (long)(it->first) * it->second;
    }
    count += it->second;
  }
  cout << sum << endl;
}