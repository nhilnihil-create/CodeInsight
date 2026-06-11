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
int N,A,B,C;
vector<int>p;
vector<int>l(100);
int ans=999999999;
void score(vector<int>p){
  int suma=0,sumb=0,sumc=0,cnta=0,cntb=0,cntc=0;
  for(int i=0;i<N;i++){
    if(p[i]==1){suma+=l[i];cnta++;}
    if(p[i]==2){sumb+=l[i];cntb++;}
    if(p[i]==3){sumc+=l[i];cntc++;}
  }
  if(cnta==0||cntb==0||cntc==0){return;}
  int cost=abs(suma-A)+abs(sumb-B)+abs(sumc-C)+10*(cnta+cntb+cntc-3);
  ans=min(ans,cost);
  return ;
}
void dfs(vector<int>p){
 if(p.size()==N){
   score(p);
   return ;
 }
 for(int i=0;i<4;i++){
   p.push_back(i);
   dfs(p);
   p.pop_back();
 }
}

int main(){
  cin>>N>>A>>B>>C;
  for(int i=0;i<N;i++){
    cin>>l[i];
  }
  dfs(p);
  cout<<ans<<endl;
  return 0;
}