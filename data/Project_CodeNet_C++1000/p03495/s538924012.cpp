#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,char>;
using ll=long long;

int main() {
  int N, K;
  cin >> N >> K;
  int a;
  vector<int> V(N, 0);
  for (int i=0; i<N; i++) {
    cin >> a;
    V[a-1]++;
  }
  sort(V.begin(), V.end());
  int s=0;
  for (int i=0; i<N-K; i++) {
    s+=V[i];
  }
  cout << s << endl;
}
 