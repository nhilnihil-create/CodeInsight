#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
 
int main(){
  int N,M;
  cin>>N>>M;
  vector<int> T(M);
  int ans=0;
  rep(i,N){
    int K;
    cin>>K;
    rep(j,K){
      int A;
      cin>>A;
      T[A-1]++;
    }
  }
  rep(i,M){
    if(T[i]==N){
      ans++;
    }
  }
  cout<<ans<<endl;
}   