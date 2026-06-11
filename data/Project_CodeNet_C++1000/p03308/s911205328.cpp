#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> A(N);

  rep(i, 0, N) cin >> A.at(i);

  sort(A.begin(), A.end());
  cout << A.back()-A.front() << endl;
}
