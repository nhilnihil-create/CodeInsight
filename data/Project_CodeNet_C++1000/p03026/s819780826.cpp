#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
typedef pair<ll,ll> P;
int main(){
  int n;
  cin>>n;
  vector<int>a(n-1),b(n-1),c(n),ans(n);
  vector<int>d[n];
  rep(i,n-1){
    cin>>a.at(i)>>b.at(i);
    a.at(i)--;
    b.at(i)--;
    d[a[i]].push_back(b[i]);
    d[b[i]].push_back(a[i]);
  }
  int to=0;
  rep(i,n){
    cin>>c.at(i);
  }
  sort(c.begin(),c.end());
  reverse(c.begin(),c.end());
  rep2(i,1,n){
    to+=c[i];
  }
  queue<int>q;
  q.push(0);
  vector<bool>v(n);
  v[0]=true;
  int p=0;
  while(!q.empty()){
    int now=q.front();q.pop();
    v[now]=true;
    rep(i,d[now].size()){
      if(!v[d[now][i]]){
        q.push(d[now][i]);
      }
    }
    ans[now]=c[p];
    p++;
  }
  cout<<to<<endl;
  rep(i,n){
    cout<<ans.at(i)<<" ";
  }
  cout<<endl;
}