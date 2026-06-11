#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

int P[100010], Y[100010], C[100010];
pair<int, int> PY[100010];
map<int, int> X;

int main() {
  int N, M; cin >> N >> M;
  for (int i = 0; i < M; i++) cin >> P[i] >> Y[i];
  for (int i = 0; i < M; i++) PY[i] = make_pair(P[i], Y[i]);
  sort(PY, PY+M, [](const auto a, const auto b) {
    return a.second < b.second;
  });
  for (int i = 0; i < N; i++) C[i] = 0;
  for (int i = 0; i < M; i++) X[PY[i].second] = ++C[PY[i].first-1];
  for (int i = 0; i < M; i++) printf("%06d%06d\n", P[i], X[Y[i]]);
}