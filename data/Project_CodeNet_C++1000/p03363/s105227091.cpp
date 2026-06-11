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

int main(){
  int N;
  cin>>N;
  vector<int>a(N);
  vector<int64_t>sum(N+1);
  sum[0]=0;
  for(int i=0;i<N;i++){
    cin>>a[i];
    sum[i+1]=sum[i]+a[i];
  }
  sort(sum.begin(),sum.end());
  int64_t ans=0,cnt=0;
  for(int i=0;i<=N;i++){
   cnt++;
   if(i==N||sum[i]!=sum[i+1]){
     ans+=cnt*(cnt-1)/2;
     cnt=0;
   }
  }
  cout<<ans<<endl;
  return 0;
}