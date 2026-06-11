#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;

int main() {
  int N, M, S=0;
  cin >> N >> M;
  vector<int> X(M), V(M-1);
  for (int i=0; i<M; i++) {
    cin >> X[i];
  }
  sort(X.begin(), X.end());
  for (int i=1; i<M; i++) {
    V[i-1]=X[i]-X[i-1];
    S+=V[i-1];
  }
  sort(V.begin(), V.end());
  reverse(V.begin(), V.end());
  
  if (M-N<=0) {cout << 0 << endl;}
  else {
    for (int i=0; i<N-1; i++) {
      S-=V[i];
    }
    cout << S << endl;
  }
}