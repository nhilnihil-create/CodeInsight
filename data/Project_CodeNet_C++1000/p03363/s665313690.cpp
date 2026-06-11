#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;

int main() {
  int64_t N; cin>>N;
  vector<int64_t> S(N);
  rep(i,N){
    cin>>S.at(i);
    if(i>0) S.at(i)+=S.at(i-1);
  }
  sort(S.begin(),S.end());
  S.push_back(-1*INF);
  int64_t count=1,ans=0,cz=0;
  for(int i=1;i<(int)S.size();i++){
    if(S.at(i)==0) continue;
    else if(S.at(i)==S.at(i-1)){
      count++;
    }
    else{
      ans+=count*(count-1)/2;
      count=1;
    }
  }
  rep(i,N) if(S.at(i)==0) cz++;
  cout<<ans+cz*(cz+1)/2<<endl;
}
