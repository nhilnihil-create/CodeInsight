#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 10000000000
#define MAX 1000010
#define MOD 1000000007

using ll = long long;
using Graph = vector<vector<int>>;


int main(){
  int N;cin>>N;
  string S; cin>>S;
  int res = 0;
  rep1(i,N){
    set<char> s1,s2;
    rep(j,N){
      if(j<i)s1.insert(S.at(j));
      else s2.insert(S.at(j));
    }
    int tmp = 0;
    for(auto c:s1){
      if(s2.count(c))tmp++;
    }
    res=max(res,tmp);
  }
  cout<<res<<endl;
}