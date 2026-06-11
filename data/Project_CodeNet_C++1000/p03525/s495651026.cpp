#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
  int N; cin >> N;
  int D[N], E[N]; for (int i = 0; i < N; i++) cin >> D[i];
  sort(D, D+N);
  if (D[0] == 0) {
    cout << 0 << endl; return 0;
  }
  int f = 1, min_dist = 50;
  for (int i = 0; i < N; i++) {
    E[i] = (D[i] * f + 24) % 24;
    f *= -1;
  }
  for (int i = 0; i < N; i++) {
    for (int j = i+1; j < N; j++) {
      min_dist = min(min_dist, abs(E[i] - E[j]));
    }
    min_dist = min(min_dist, D[i]);
  }
  cout<<min_dist<<endl;
}