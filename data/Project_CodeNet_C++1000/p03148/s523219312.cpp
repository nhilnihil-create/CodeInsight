#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n,k;
  cin>>n>>k;
  vector<int> v[n];
  rep(i,0,n){
    int a,d;
    cin>>a>>d;
    v[a-1].push_back(d);
  }
  rep(i,0,n){
    sort(v[i].begin(),v[i].end(),greater<int>());
  }
  priority_queue<int> t;
  priority_queue<int> f;
  rep(i,0,n){
    int l=v[i].size();
    rep(j,0,l){
      if(j==0) t.push(v[i][j]);
      else f.push(v[i][j]);
    }
  }
  priority_queue<int> tt;
  priority_queue<int,vector<int>,greater<int>> ff;
  ll sum=0;
  ll size=0;
  rep(i,0,k){
    if(t.empty()){
      ff.push(f.top());
      sum+=f.top();
      f.pop();
    }
    else if(f.empty()){
      tt.push(t.top());
      sum+=t.top();
      size++;
      t.pop();
    }
    else if(t.top()>=f.top()){
      tt.push(t.top());
      sum+=t.top();
      size++;
      t.pop();
    }
    else{
      ff.push(f.top());
      sum+=f.top();
      f.pop();
    }
  }
  ll ans=sum+size*size;
  while(t.size() && ff.size()){
    tt.push(t.top());
    sum+=t.top();
    size++;
    t.pop();
    sum-=ff.top();
    ff.pop();
    ans=max(ans,sum+size*size);
  }
  cout<<ans<<endl;
}