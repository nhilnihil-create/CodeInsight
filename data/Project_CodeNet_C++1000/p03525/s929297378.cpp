#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  int N;
  cin>>N;
  map<int,int> m;
  m[0]++;
  for(int i = 0; i < N; i++) {
    int t;
    cin>>t;
    m[t]++;
  }
  int ans=INF;
  vector<int> q;
  int cnt = 1;
  for(auto x:m){
    if(x.second>=3||(x.first==0&&x.second>=2)||(x.first==12&&x.second>=2)){
      ans=0;
      break;
    }
    else {
      if(x.second==2){
        q.push_back(x.first);
        q.push_back(24-x.first);
      }
      if(x.second==1){
        if(cnt==1) q.push_back(x.first);
        if(cnt==0) q.push_back(24-x.first);
        cnt=1-cnt;
      }
      sort(q.begin(),q.end());
      for(int i = 0; i < (int)q.size()-1;i++){
        chmin(ans,q[i+1]-q[i]);
      }
      chmin(ans,24-*(q.end()-1));
    }
  }
  cout<<ans<<endl;
}