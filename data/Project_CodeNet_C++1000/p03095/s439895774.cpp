#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;

int main() {
  int N,count=2;
  cin>>N;
  vector<char> S(N);
  rep(i,N) cin>>S.at(i);
  sort(S.begin(),S.end());
  vector<int> num;
  if(N==1) cout<<1;
  else{
    S.push_back(10);
    for(int i=1;i<N+1;i++){
      if(S.at(i)==S.at(i-1)) count++;
      else{
        num.push_back(count);
        count=2;
      }
    }
    int64_t ans=1;
    rep(i,num.size()){
      ans*=num.at(i);
      ans%=MOD;
    }
    cout<<ans-1;
  }
}

