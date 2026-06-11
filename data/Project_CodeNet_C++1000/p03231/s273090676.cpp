#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int main() {
  int64_t N,M;
  cin>>N>>M;
  string s,t;
  cin>>s>>t;
  int64_t L=N/__gcd(N,M)*M;
  if(s[0]!=t[0]){cout<<-1<<endl;return 0;}
  if(__gcd(N,M)==1){cout<<L<<endl;}
  else{
    vector<char>X(L,'1');
    for(int i=0;i<N;i++){
      X[i*L/N]=s[i];
    }
    for(int i=0;i<M;i++){
      if(X[i*L/M]!='1'&&X[i*L/M]!=t[i]){cout<<-1<<endl;return 0;}
    }
    cout<<L<<endl;
  }
  return 0;
}