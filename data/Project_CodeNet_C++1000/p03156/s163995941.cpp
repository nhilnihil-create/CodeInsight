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
  int N,A,B;
  cin>>N>>A>>B;
  vector<int>P(N);
  map<int,int>k;
  k[0]=0,k[1]=0,k[2]=0;
  for(int i=0;i<N;i++){
    cin>>P[i];
    if(P[i]<=A){k[0]++;}
    else if(P[i]>A&&P[i]<=B){k[1]++;}
    else{k[2]++;}
  }
  int MIN=999;
  for(auto c:k){
    MIN=min(MIN,c.second);
  }
  cout<<MIN<<endl;
  return 0;
}