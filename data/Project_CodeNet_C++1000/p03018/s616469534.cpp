#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;

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
  string s;
  cin>>s;
  int n=s.size();
  vector<int>bc(n);
  int cntbc=0;
  for(int i=n-1;i>=0;i--){
    if(s[i]=='A'){bc[i]=cntbc;}
    else if(i-1>=0&&s.substr(i-1,2)=="BC"){cntbc++;bc[i-1]=cntbc;i--;}
    else if(i-1>=0&&s.substr(i-1,2)!="BC"){cntbc=0;}
  }
  
  int64_t ans=0;
  for(int i=n-1;i>=0;i--){
    if(i+1<=n-1&&s[i]=='A'){ans+=bc[i+1];}
  }
  cout<<ans<<endl;
  return 0;
}