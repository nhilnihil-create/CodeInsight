#include<bits/stdc++.h>
using namespace std;
using ll=long long;


int main(){
  int n,m;
  cin >> n >> m;
  vector<ll> g[3];
  for(int i=0;i<n;++i){
    for(int j=0;j<3;++j){
      ll x;
      cin >> x;
      g[j].push_back(x);
    }
  }

  ll cal=0;
  for(int bit=0;bit<(1<<3);++bit){
    vector<ll> kouho;
    for(int i=0;i<n;++i){
      ll tmp=0;
      for(int j=0;j<3;++j){
        if(bit &(1<<j)) tmp+=g[j][i];
        else tmp-=g[j][i];
      }
      kouho.push_back(tmp);
    }
    sort(kouho.rbegin(),kouho.rend());
    ll res=0;
    for(int i=0;i<m;++i){
      res+=kouho[i];
    }
    cal=max(cal,res);
  }

  cout << cal << endl;
  return 0;

}
