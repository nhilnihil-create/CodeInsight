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
  int N,M;
  cin>>N>>M;
  map<int,int> m;
  m[1]=2;
  m[2]=5;
  m[3]=5;
  m[4]=4;
  m[5]=5;
  m[6]=6;
  m[7]=3;
  m[8]=7;
  m[9]=6;
  map<int,int> d;
  for(int i = 0; i < M; i++){
    int x;
    cin>>x;
    chmax(d[m[x]],x);
  }
  vector<int> dp(N+1,-1);
  dp[0]=0;
  for(int i = 0;i<N+1;i++){
    for(auto x:d){
      if(i<x.first) continue;
      if(dp[i-x.first]==-1) continue;
      chmax(dp[i],dp[i-x.first]+1);
    }
  }
  vector<int> s;
  for(auto x:d) s.push_back(x.second);
  sort(s.begin(),s.end());
  reverse(s.begin(),s.end());
  int cnt = 0;
  for(int i = 0; i < dp[N]-1; i++){
    for(int j = 0; j < (int)s.size();j++){
      if(N-cnt-m[s[j]]>=0&&dp[N-cnt]==dp[N-cnt-m[s[j]]]+1&&dp[N-cnt-m[s[j]]]!=-1) {
        cout<<s[j];
        cnt+=m[s[j]];
        break;
      }
    }
  }
  cout<<d[N-cnt]<<endl;
}