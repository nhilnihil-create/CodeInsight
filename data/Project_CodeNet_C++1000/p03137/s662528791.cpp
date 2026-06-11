#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
int64_t MOD=1000000007;

int main() {
  int N,M;
  cin>>N>>M;
  vector<int> S(M);
  for(int i=0;i<M;i++) cin>>S.at(i);
  sort(S.begin(),S.end());
  reverse(S.begin(),S.end());
  vector<int> R(M-1);
  int64_t ans=0;
  for(int i=0;i<M-1;i++) R.at(i)=S.at(i)-S.at(i+1);
  sort(R.begin(),R.end());
  reverse(R.begin(),R.end());
  for(int i=0;i<M-1;i++){
    if(i<N-1)continue;
    ans+=R.at(i);
  }
  cout<<ans<<endl;
}
