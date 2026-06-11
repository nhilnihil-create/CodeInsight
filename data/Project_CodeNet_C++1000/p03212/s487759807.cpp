#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <cmath>
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
int N;
int cnt=0;
void check(int64_t x){
    string t=to_string(x);
    set<int>k;
    for(int i=0;i<t.size();i++){
      k.insert(t[i]);
    }
    if(k.size()<=2){return;}
    else if(x<=N){cnt++;}
    return;
  }
void dfs(int64_t x){
  check(x);
  if(x<=1000000000){
    dfs(10*x+3);
    dfs(10*x+5);
    dfs(10*x+7);
  }
}
int main(){
  cin>>N;
  dfs(0);
  cout<<cnt<<endl;
  return 0;
}