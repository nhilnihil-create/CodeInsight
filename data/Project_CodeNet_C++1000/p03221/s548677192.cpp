#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <cmath>
#include <algorithm>
#include <vector>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>func(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p;
}

int main(){
  int N,M;
  cin>>N>>M;
  vector<int>P(M);
  vector<int>Y(M);
  for(int i=0;i<M;i++){
    cin>>P[i]>>Y[i];
    P[i]--;
  }
  vector<vector<int>>s(N);
  for(int i=0;i<M;i++){
    s[P[i]].push_back(Y[i]);
  }
  for(int i=0;i<N;i++){
    sort(s[i].begin(),s[i].end());
  }
  for(int i=0;i<M;i++){
    int v=P[i];
    printf("%06d",v+1);
    int id=lower_bound(s[v].begin(),s[v].end(),Y[i])-s[v].begin();
    printf("%06d\n",id+1);
  }
  return 0;
}