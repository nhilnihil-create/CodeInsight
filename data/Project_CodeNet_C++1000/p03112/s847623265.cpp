#include<bits/stdc++.h>
using namespace std;
int64_t inf=1e11;
int main() {
  int64_t a,b,q,x,i,s1,s2,t1,t2,ans;
  cin>>a>>b>>q;
  vector<int64_t> s(a),t(b);
  for(i=0;i<a;i++) cin>>s.at(i);
  for(i=0;i<b;i++) cin>>t.at(i);
  sort(s.begin(),s.end());
  sort(t.begin(),t.end());
  for(i=0;i<q;i++){
    cin>>x;
    auto it=upper_bound(s.begin(),s.end(),x);
    if(it==s.end()) s2=inf;
    else s2=*it;
    if(it==s.begin()) s1=-inf;
    else s1=*prev(it,1);
    it=upper_bound(t.begin(),t.end(),x);
    if(it==t.end()) t2=inf;
    else t2=*it;
    if(it==t.begin()) t1=-inf;
    else t1=*prev(it,1);
    ans=min(x-min(s1,t1),max(s2,t2)-x);
    ans=min(ans,x-s1+t2-s1);
    ans=min(ans,x-t1+s2-t1);
    ans=min(ans,s2-x+s2-t1);
    ans=min(ans,t2-x+t2-s1);
    cout<<ans<<endl;
  }
}