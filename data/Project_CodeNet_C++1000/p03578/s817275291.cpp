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
  int N;
  cin>>N;
  vector<int>D(N);
  map<int,int>a;
  for(int i=0;i<N;i++){cin>>D[i];a[D[i]]++;}
  int M;
  cin>>M;
  vector<int>T(M);
  map<int,int>b;
  for(int i=0;i<M;i++){cin>>T[i];b[T[i]]++;}
  if(N<M){cout<<"NO"<<endl;return 0;}
  for(auto s:b){
    int x=s.first;
    int y=s.second;
    if(y>a[x]){cout<<"NO"<<endl;return 0;}
  }
  cout<<"YES"<<endl;

  return 0;
}