#include<iostream>
#include<algorithm>
using namespace std;

int N; pair<int, int> S[100010];

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    S[i] = make_pair(a, b);
  }
  sort(S, S+N, [](auto a, auto b) {
    return a.first + a.second > b.first + b.second;
  });
  long tak=0, aok=0;
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0) tak += S[i].first;
    else aok += S[i].second;
  }
  cout << tak - aok << endl;
}