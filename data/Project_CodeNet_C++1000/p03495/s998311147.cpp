#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
  int N,K,a;
  cin >> N >> K;
  vector<int> count(N);
  rep(i,N) {
    cin >> a;
    count[a-1]++;
  }
  sort(count.begin(),count.end());
  int ans=0;
  for(int i=0; i<N-K; i++) ans += count[i];
  cout << ans << endl;
}