#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
  string s; cin>>s;
  ll res = 700;
  if(s.at(0)=='o')res+=100;
  if(s.at(1)=='o')res+=100;
  if(s.at(2)=='o')res+=100;
  cout<<res<<endl;
}
