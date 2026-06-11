#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;

int main() {
  int N;
  cin >> N;
  vector<int> X(N), V(N);
  for (int i=0; i<N; i++) {
    cin >> X[i];
    V[i]=X[i];
  }
  sort(V.begin(), V.end());
  for (int i=0; i<N; i++) {
    if (X[i]<V[N/2]) {
      cout << V[N/2] << endl;
    }
    else {
      cout << V[N/2-1] << endl;
    }
  }
}
