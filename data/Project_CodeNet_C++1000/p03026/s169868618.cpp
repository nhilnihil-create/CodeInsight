#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, A[1<<18], B[1<<18], S, cnt;
vector<int> X[1<<18];
bool used[1<<18];

void dfs(int pos) {
  used[pos] = true;
  for(int i = 0; i < X[pos].size(); i++) {
    if(used[X[pos][i]] == true) continue;
    dfs(X[pos][i]);
  }
  B[pos] = A[cnt];
  cnt++;
}

int main() {
  cin >> N;
  for(int i = 1; i <= N-1; i++) {
    int p, q; cin >> p >> q;
    X[p].push_back(q);
    X[q].push_back(p);
  }

  for(int i = 0; i < N; i++) cin >> A[i];
  sort(A, A+N);
  for(int i = 0; i < N-1; i++) S += A[i];

  dfs(1);

  cout << S << endl;
  for(int i = 1; i <= N; i++) {
    cout << B[i];
    if(i == N) cout << endl;
    else cout << " ";
  }
  return 0;
}
