#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;

void QA(bool x){
  if(x) cout<<"Yes";
  else cout<<"No";
  return;
}


int main() {
  bool finish=true;
  int N; cin>>N;
  vector<string> S(N);
  rep(i,N) cin>>S.at(i);
  for(int i=1;i<N;i++) if(S.at(i-1).at(S.at(i-1).size()-1)!=S.at(i).at(0))finish=false;
  sort(S.begin(),S.end());
  for(int i=1;i<N;i++) if(S.at(i-1)==S.at(i)) finish=false;
  QA(finish);
}

