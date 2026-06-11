#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
ll l=1000000007;
string alphabet="abcdefghijklmnopqrstuvwxyz";
using graph = vector<vector<int>>;
double pi=3.14159265358979;
int main() {
  int n,m; cin>>n>>m;
  graph v(m);
  rep(i,m){
    int k; cin>>k;
    rep(j,k){
      int s; cin>>s; s--;
      v[i].push_back(s);
    }
  }
  vector<int> p(m);
  rep(i,m){cin>>p[i];}
  int ans=0;
  for(int tmp=0;  tmp<(1<<10); tmp++){
    bitset<10> bs(tmp);
    
    bool b=true;
    rep(i,m){
      int c=0; 
      for(int j: v[i]){c+=bs[j];}
      c %=2;
      if(c!=p[i]){b=false;break;}
    }
    if(b){ans++;}
  }
  int x= pow(2,10-n);
  cout<<ans/x;
}