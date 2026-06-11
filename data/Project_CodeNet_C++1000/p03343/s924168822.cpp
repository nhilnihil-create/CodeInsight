#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
 int n,k,q;
 cin>>n>>k>>q;
int a[n];
pair<int,int> t[n];
for(int i=0;i<n;i++){
  cin>>a[i];
  t[i]=make_pair(a[i],i);
}
sort(t,t+n);
int root= t[0].second,node;
int l[n],r[n];fill(l,l+n,n);fill(r,r+n,n);

for(int i=1;i<n;i++){
  node=root;
  while(true){
    if(t[i].second<node){
      if(l[node]==n){
        l[node]=t[i].second;
        break;
      }
      node=l[node];
    }else{
      if(r[node]==n){
        r[node]=t[i].second;
        break;
      }
      node=r[node];
    }   
  }
}
//cerr<<'y';
priority_queue<int,vector<int>,greater<int>> que[n];
priority_queue<int> qq;
int ans=MOD*2000;
for(int i=n-1;i>=0;i--){
  node=t[i].second;
  if(l[node]!=n)swap(que[node],que[l[node]]);
  if(r[node]!=n){
    while(!que[r[node]].empty()){
      que[node].push(que[r[node]].top());
      que[r[node]].pop();
    }
  }
  if(que[node].size()<k-1)que[node].push(a[node]);
  else{
    qq.push(a[node]);
    while(que[node].size()>k-1){
      qq.push(que[node].top());
      que[node].pop();
    }
    while(qq.size()>q)qq.pop();
    if(qq.size()==q)ans=min(ans,qq.top()-a[node]);
  }
}
cout<<ans;
return 0;
}
