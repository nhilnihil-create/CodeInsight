#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main()
{
  ll K; cin>>K;
  vector<ll> A(K); rep(i,K) cin>>A[i];
  //vector<ll> A(100000,1000000000);
  
  vector<ll> up(K+1,2),down(K+1,2);
  if(A[K-1]!=2) {cout<<-1<<endl; return 0;}
  for(int i=K-1;i>=0;i--){
    up[i]=up[i+1]+(A[i]-1); if(i!=0) up[i]=up[i]/A[i-1]*A[i-1];
    down[i]=down[i+1]; if(i!=0&&down[i]%A[i-1]!=0) down[i]=(down[i]/A[i-1]+1)*A[i-1];
    
    if(up[i]<down[i]) {cout<<-1<<endl; return 0;}
  }
  
  cout<<down[0]<<" "<<up[0]<<endl;
    
  return 0;
}