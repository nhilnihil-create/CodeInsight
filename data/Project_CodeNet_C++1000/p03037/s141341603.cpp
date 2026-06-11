#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int N,M; cin >> N >> M;

  vector<int> L(M), R(M);
  for(int i = 0; i < M; i++){
    cin >> L[i] >> R[i];
  }
  sort(L.begin(), L.end());
  sort(R.begin(), R.end());

  int ans = R[0] - L[M-1];

  cout << (ans < 0 ? 0 : ans + 1) << endl;

}
