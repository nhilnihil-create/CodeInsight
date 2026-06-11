#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
int main(void){
  int N, X;
  cin >> N >> X;
  int s = 0, M = 1000000;
  vector<int> m(101);
  for(int i = 0; i < N; i++){
    cin >> m[i];
    s += m[i];
    if(m[i] < M){
      M = m[i];
    }
  }
  int ans = N + (X - s) / M;
  cout << ans << endl;
  return 0;
}