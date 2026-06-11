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
  int N,Y;
  cin>>N>>Y;
  for(int i=0;i<=Y/10000;i++){
    for(int j=0;j<=Y/5000;j++){
      int c=N-i-j;
      if(c>=0&&10000*i+5000*j+1000*c==Y){
        cout<<i<<" "<<j<<" "<<c<<endl;return 0;
      }
    }
  }
  cout<<"-1 -1 -1"<<endl;
  return 0;
}