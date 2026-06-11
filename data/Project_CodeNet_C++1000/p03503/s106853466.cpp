#include <bits/stdc++.h>
using namespace std;
#include <math.h>
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


int a[10];
int64_t ans=-999999999999999;
int N;
int F[200][10];
int P[200][11];

void func(void){
  int64_t score=0;
  for(int i=0;i<N;i++){
   int cnt=0;
   for(int j=0;j<10;j++){
    if(a[j]==1&&F[i][j]==1){
      cnt++;
    }
   }
   score+=P[i][cnt];
  }
  ans=max(ans,score);
}

void dfs(int pos){
  if(pos==10){
    bool ok=false;
    for(int i=0;i<10;i++){
      if(a[i]==1){ok=true;}
    }
    if(ok){func() ;}
    return ;
  }
  a[pos]=0;dfs(pos+1);
  a[pos]=1;dfs(pos+1);
}

int main() {
  cin>>N;
  for(int i=0;i<N;i++){
    for(int j=0;j<10;j++){
      cin>>F[i][j];
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<11;j++){
      cin>>P[i][j];
    }
  }
  dfs(0);

  cout<<ans<<endl;
  return 0;
}