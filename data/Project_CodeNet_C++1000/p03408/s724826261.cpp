#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
  int N;
  cin >> N;
  map<string,int> br;
  string tmp;
  rep(i,N) {
    cin >> tmp;
    br[tmp]++;
  }
  int M;
  cin >> M;
  rep(i,M) {
    cin >> tmp;
    br[tmp]--;
  }

  int ans=0;
  for(auto itr : br) {
    ans = max(ans,itr.second);
  }

  cout << ans << endl;
}