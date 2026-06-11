#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
  int x; cin>>x;
  ll res = 1;
  for(int i = 2; i <= sqrt(x); i++){
    for(int p = 2; pow(i,p) <= x; p++){
      res = max((ll)pow(i,p),res);
      }

    }
    cout<<res<<endl;

  }

