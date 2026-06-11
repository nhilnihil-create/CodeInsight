#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  vector<int> l(Q), r(Q);
  for(int i = 0; i < Q; i++) {
    cin >> l[i] >> r[i];
  }

  vector<int> cnt(N+1, 0);
  for(int i = 0; i < N; i++) {
    if(S[i] == 'A' && S[i+1] == 'C') {
      cnt[i+1] = cnt[i] + 1;
    }
    else {
      cnt[i+1] = cnt[i];
    }
  }
  cout << endl;

  for(int i = 0; i < Q; i++) {
    cout << cnt[r[i]-1] - cnt[l[i]-1] << endl;
  }

  return 0;
}
