#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
// https://emtubasa.hateblo.jp/entry/2019/02/14/000000_2
int main(){
  string S;
  int N;
  cin >> S ; N = S.length();
  int ans = INF;
  for(int i = 0; i < N-1; i ++){
    if(S[i]!=S[i+1]) {
      ans = min(ans,max(i+1,N-i-1));
    }
  }
  if(ans==INF) ans = N;
  cout << ans << endl;
  return 0;
}
