#include<iostream>
#include<map>
using namespace std;

int X[100010];

int main() {
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> X[i];
  int min_dist = (1<<30);
  for (int i = 0; i < N-K+1; i++) {
    if (X[i+K-1] <= 0) {
      if (-X[i] < min_dist) {
        min_dist = -X[i];
      }
    } else if (X[i] < 0) {
      int dist = min(-X[i] * 2 + X[i+K-1], -X[i] + X[i+K-1] * 2);
      if (dist < min_dist) {
        min_dist = dist;
      }
    } else {
      if (X[i+K-1] < min_dist) {
        min_dist = X[i+K-1];
      }
    }
  }
  cout << min_dist << endl;
}