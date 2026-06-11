#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

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
  vector<int>v(N);
  map<int,int>odd;
  map<int,int>even;
  for(int i=0;i<N;i++){
    cin>>v[i];
    if(i%2==0){even[v[i]]++;}
    else{odd[v[i]]++;}
  }

  int MO=0,MCO=0;
  for(auto c:odd){
    if(c.second>MCO){MO=c.first;MCO=c.second;}
  }
  int SO=0;
  for(auto c:odd){
    if(c.first!=MO&&c.second>SO){SO=c.second;}
  }

  int ME=0,MCE=0;
  for(auto c:even){
    if(c.second>MCE){ME=c.first;MCE=c.second;}
  }
  int SE=0;
  for(auto c:even){
    if(c.first!=ME&&c.second>SE){SE=c.second;}
  }

  if(MO!=ME){
    cout<<(N/2-MCO)+(N/2-MCE)<<endl;
  }
  else{
    if((N/2-MCO)+(N/2-SE)<(N/2-MCE)+(N/2-SO)){
      cout<<(N/2-MCO)+(N/2-SE)<<endl;
    }
    else{
      cout<<(N/2-MCE)+(N/2-SO)<<endl;
    }
  }
  
  return 0;
}