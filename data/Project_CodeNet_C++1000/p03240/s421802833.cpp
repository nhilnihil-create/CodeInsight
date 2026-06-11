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
  int N;
  cin>>N;
  vector<int64_t>X(N),Y(N),h(N);
  for(int i=0;i<N;i++){
    cin>>X[i]>>Y[i]>>h[i];
  }
  for(int x=0;x<=100;x++){
    for(int y=0;y<=100;y++){
      int64_t H=0;
      for(int i=0;i<N;i++){
        if(h[i]==0){continue;}
        H=h[i]+abs(x-X[i])+abs(y-Y[i]);
        break;
      }
      bool ok=true;
      for(int i=0;i<N;i++){
        if(max(H-abs(x-X[i])-abs(y-Y[i]),(int64_t)0)!=h[i]){
          ok=false;
        }
      }
      if(ok){cout<<x<<" "<<y<<" "<<H<<endl;return 0;}
    }
  }
  return 0;
}