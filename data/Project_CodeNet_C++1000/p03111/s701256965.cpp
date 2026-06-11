#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int N,A,B,C;
  cin>>N>>A>>B>>C;
  vector<int> ban(N);
  rep(i,N) cin>>ban[i];
  int ans = INF;
  for(int i = 0; i < (1<<(2*N));i++){
    bitset<20> bi(i);
    vector<int> v(N);
    int cnt=0;
    for(int j = 0; j < N; j++){
      if(bi.test(2*j)&&bi.test(2*j+1)) v[j]=0;
      if(!bi.test(2*j)&&bi.test(2*j+1)) v[j]=1;
      if(bi.test(2*j)&&!bi.test(2*j+1)) v[j]=2;
      if(!bi.test(2*j)&&!bi.test(2*j+1)) v[j]=3;
    }
    vector<vector<int>> vv(4);
    rep(j,N) {
      vv[v[j]].push_back(ban[j]);
    }
    if((int)vv[0].size()==0||(int)vv[1].size()==0||(int)vv[2].size()==0)continue;
    rep(j,3){
      cnt+=((int)vv[j].size()-1)*10;
      int s=0;
      for(auto x:vv[j]) s+=x;
      if(j==0)cnt+=abs(s-A);
      if(j==1)cnt+=abs(s-B);
      if(j==2)cnt+=abs(s-C);
    }
    chmin(ans,cnt);
  }
  cout<<ans<<endl;
}