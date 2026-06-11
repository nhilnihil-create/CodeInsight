#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

string func(int n){
  string s;
  string t=to_string(n);
  rep(i,0,6-t.size()){
    s+='0';
  }
  return s+t;
}

int main(){
  int n,m;
  cin>>n>>m;
  vector<P> a[n];
  rep(i,0,m){
    int p,y;
    cin>>p>>y;
    a[p-1].push_back(P(y,i));
  }
  rep(i,0,n){
    sort(a[i].begin(),a[i].end());
  }
  string ans[m];
  rep(i,0,n){
    rep(j,0,a[i].size()){
      string s;
      s+=func(i+1);
      s+=func(j+1);
      ans[a[i][j].second]=s;
    }
  }
  rep(i,0,m){
    cout<<ans[i]<<endl;
  }
}