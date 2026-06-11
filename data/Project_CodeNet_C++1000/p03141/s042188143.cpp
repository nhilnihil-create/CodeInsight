#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<long long> A(N), B(N);
  vector<pair<long long, int>> C;
  for (int i = 0; i < N; i++) {
    cin >> A.at(i) >> B.at(i);
    C.push_back(make_pair(A.at(i) + B.at(i), i));
  }
  sort(C.begin(), C.end(), greater<pair<long long, int>>());
  long long a = 0;
  long long b = 0;
  for (int i = 0; i < N; i++) {
    int index = C.at(i).second;
    if (i % 2 == 0) a += A.at(index);
    else b += B.at(index);
  }
  cout << a - b << endl;
}