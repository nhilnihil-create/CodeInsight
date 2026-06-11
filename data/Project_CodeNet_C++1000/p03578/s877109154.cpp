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
  int N,M;
  cin>>N;
  vector<int>D(N);
  for(int i=0;i<N;i++){
    cin>>D[i];
  }
  cin>>M;
  vector<int>T(M);
  for(int i=0;i<M;i++){
    cin>>T[i];
  }
 // if(N<M){cout<<"NO"<<endl;return 0;}

  map<int,int>Q;
  for(int i=0;i<N;i++){
    Q[D[i]]++;
  }
  map<int,int>cnt;
  for(int i=0;i<M;i++){
    cnt[T[i]]++;
  }
  
  for(int i=0;i<M;i++){
    if(cnt[T[i]]>Q[T[i]]){cout<<"NO"<<endl;return 0;}
  }
  cout<<"YES"<<endl;
  return 0;
}