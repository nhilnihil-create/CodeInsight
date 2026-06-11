#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  int A, B; cin >> A >> B;
  vector<int> x, y, z;
  for (int i = 0; i < N; i++) {
    int P; cin >> P;
    if (P <= A) x.push_back(P);
    else if (P <= B) y.push_back(P);
    else z.push_back(P);
  }
  vector<int> v;
  v.push_back(x.size());
  v.push_back(y.size());
  v.push_back(z.size());
  sort(v.begin(), v.end());
  cout << v.at(0) << endl;
}