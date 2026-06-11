#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 10000000000
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
  ll N, M;  cin>>N>>M;
  for(ll i = M/N; i>= 1; i--){
    if(M%i==0&&M/i>=N){
      cout<<i<<endl;
      return 0;
    }
  }
}