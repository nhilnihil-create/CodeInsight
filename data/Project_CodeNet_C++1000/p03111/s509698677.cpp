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
vector<int> v(100000);
vector<int> l(100000);
int ans=999999999;
void calc(vector<int> &v){
  //cout<<v[0]<<v[1]<<v[2]<<v[3]<<v[4]<<endl;
  int suma=0,sumb=0,sumc=0;
  int cnta=0,cntb=0,cntc=0;
 for(int i=0;i<N;i++){
   if(v[i]==0){suma+=l[i];cnta++;}
   if(v[i]==1){sumb+=l[i];cntb++;}
   if(v[i]==2){sumc+=l[i];cntc++;}
 }
 if(cnta==0||cntb==0||cntc==0){return;}
 int cu=abs(A-suma)+abs(B-sumb)+abs(C-sumc)+10*(cnta+cntb+cntc-3);
 ans=min(ans,cu);
 return;
}

void dfs(int depth,vector<int> &v){
  if(depth==N){
    calc(v);
    return;
  }
  for(int i=0;i<4;i++){
    v[depth]=i;
    dfs(depth+1,v);
  }
}
int main(){
  cin>>N>>A>>B>>C;
  for(int i=0;i<N;i++){
    cin>>l[i]; 
  }
  dfs(0,v);
  cout<<ans<<endl;
  return 0;
}