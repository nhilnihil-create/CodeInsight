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
int func2(int x){
  int sum=0;
  while(x>0){
    sum+=x%10;
    x/=10;
  }
  return sum;
}

int main() {
  int n,a,b;
  cin>>n>>a>>b;
  int sumb=0,suma=0;
  for(int i=1;i<=n;i++){
    if(func2(i)<=b){sumb+=i;}
    if(func2(i)<=a-1){suma+=i;}
  }
  cout<<sumb-suma<<endl;
  return 0;
}