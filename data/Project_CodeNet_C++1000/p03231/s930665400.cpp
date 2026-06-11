#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
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
  int64_t N,M;
  cin>>N>>M;
  string s,t;
  cin>>s>>t;
  int64_t n=__gcd(N,M);
  if(s[0]!=t[0]){cout<<-1<<endl;}
  else{
    if(n==1){cout<<N*M/n<<endl;return 0;}
    for(int i=1;i<n;i++){
    if(s[i*N/n]!=t[i*M/n]){cout<<-1<<endl;return 0;}
  }
    cout<<N*M/n<<endl;
  }
  return 0;
}