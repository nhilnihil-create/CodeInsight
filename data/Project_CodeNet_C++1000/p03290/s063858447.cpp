#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>prime_factorize(int64_t x){
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

int main() {
  int D,G;
  cin>>D>>G;
  vector<int>p(D),c(D);
  for(int i=0;i<D;i++){
    cin>>p[i]>>c[i];
  }

  int ans=9999;
  for(int q=0;q<(1<<D);q++){
    int sum=0,cnt=0;
    vector<bool>use(D,true);
    for(int i=0;i<D;i++){
      if((q>>i)&1){
        sum=sum+100*(i+1)*p[i]+c[i];
        cnt+=p[i];
        use[i]=false;
      }
    }
    int r=0;
    for(int i=D-1;i>=0;i--){
      if(use[i]){
       r=i;break;
      }
    }
    for(int i=0;i<p[r];i++){
      if(sum<G){sum+=(r+1)*100;cnt++;}
    }
    if(sum<G){continue;}
    chmin(ans,cnt);
  }
  cout<<ans<<endl;
  return 0;
}