#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  int sum;
  if(n%2==0) sum = 1+n;
  else sum = n;
  vector<int> g[n];
  rep(i,n){
    rep(j,n){
      if((i+1)+(j+1)!=sum && i > j) g[i].pb(j);      
    }
  }
  vector<pair<int,int>> ans;
  rep(i,n){
    for(auto j:g[i]){
      ans.pb(make_pair(i+1,j+1));
    }
  }
  cout << ans.size() << endl;
  rep(i,ans.size()){
    int a = ans[i].first;
    int b = ans[i].second;
    cout << a << " " << b << endl;
  }

  
  return 0;
    

}
