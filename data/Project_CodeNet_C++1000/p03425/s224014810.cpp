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
  vector<string>s(N);
  for(int i=0;i<N;i++){
    cin>>s[i];
  }
  map<char,int64_t>k;
  for(int i=0;i<N;i++){
    k[s[i][0]]++;
  }
  string t="MARCH";
  int64_t ans=0;
  for(int i=0;i<5;i++){
    for(int j=i+1;j<5;j++){
      for(int r=j+1;r<5;r++){
        ans+=k[t[i]]*k[t[j]]*k[t[r]]; 
      }
    }
  }    
  cout<<ans<<endl;
  return 0;  
}