#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>pppp(int64_t x){
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
  int N,M;
  cin>>N>>M;
  vector<int>X(M);
  for(int i=0;i<M;i++){
    cin>>X[i];
  }
  sort(X.begin(),X.end());
  if(M==1){cout<<0<<endl;}
  else{
  vector<int>k(1000000);
  int sum=0;
  for(int i=0;i<M;i++){
    if(i<M-1){k[i]=X[i+1]-X[i];sum+=k[i];}
  }

  sort(k.begin(),k.end());
  reverse(k.begin(),k.end());

  for(int i=0;i<N-1;i++){
    sum-=k[i];
  }
  cout<<sum<<endl;
  }
  return 0;
}