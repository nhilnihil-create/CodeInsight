#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  double T, A;
  cin >> N >> T >> A;

  double H[N];
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }

  vector<pair<double,int>> distances;

  for (int i = 0; i < N; i++) {
    double avg = T - H[i] * 0.006;
    distances.push_back({abs(A-avg),i+1});
  }

  sort(distances.begin(),distances.end());

  cout << distances[0].second << endl;
  return 0;
}