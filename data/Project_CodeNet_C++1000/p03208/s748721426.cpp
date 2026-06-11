#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;


int H,W,T;
string s[10];

int main(){
  int N,K;
  cin>>N>>K;
  vector<int> h(N);
  for(int i(0);i<N;i++){
    cin>>h[i];
  }
  sort(h.begin(),h.end());
  int ans(1e9);
  for(int i(K);i<=N;i++){
    ans = min(ans,h[i-1]-h[i-K]);
  }
  cout << ans << endl;
  return 0;
}
