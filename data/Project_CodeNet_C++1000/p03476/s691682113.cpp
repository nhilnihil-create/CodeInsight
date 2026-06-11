#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

bool f(int x){
  bool ok=true;
  for(int i=2;i*i<=x;i++){
    if(x%i==0){ok=false;}
  }
  return ok;
}
int main() {
  int Q;
  cin>>Q;
  vector<int>l(Q),r(Q);
  for(int i=0;i<Q;i++){
    cin>>l[i]>>r[i];
  }
  vector<int>prime(1e5+5);
  for(int i=2;i<=1e5;i++){
    if(i%2!=0&&f(i)&&f((i+1)/2)){prime[i]++;}
  }  
  for(int i=0;i<=1e5;i++){
    prime[i+1]+=prime[i];
  }
  for(int i=0;i<Q;i++){
    cout<<prime[r[i]]-prime[l[i]-1]<<endl;
  }
  return 0;  
}