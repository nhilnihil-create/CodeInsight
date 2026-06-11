#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
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
  map<int,int>k;
  for(int i=2;i<=N;i++){
    int cur=i;
    for(int j=2;j*j<=cur;j++){
      while(cur%j==0){k[j]++;cur/=j;}
    }
    if(cur!=1){k[cur]++;}
  }
  map<int,int>num;
  for(int i=1;i<=75;i++){
    for(auto c:k){
      if(c.second>=i-1){num[i]++;}
    }
  }
  cout<<num[75]+num[25]*(num[3]-1)+(num[5]-1)*num[15]+num[5]*(num[5]-1)*(num[3]-2)/2<<endl;
  return 0;  //かぶる部分をなくすために-1。num[5]が二つで数なので/2
}