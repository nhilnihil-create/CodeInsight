#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin>>n;
  vector<pair<int,int>> d(n);
  rep(i,n){
    int x,y;
    cin>>x>>y;
    d[i].first=x+y;
    d[i].second=x;
  }
  sort(d.begin(),d.end(),greater());
  ll res=0;
  rep(i,n){
    if(i%2==0){
      res+=d[i].second;
    }else{
      res-=d[i].first-d[i].second;
    }
  }
  cout<<res<<endl;
}