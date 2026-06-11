#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,q;
  cin>>a>>b>>q;
  vector<int64_t> s(a);
  for(int i=0;i<a;i++)
    cin>>s.at(i);
  vector<int64_t> t(b);
  for(int i=0;i<b;i++)
    cin>>t.at(i);
  for(int _=0;_<q;_++){
    int64_t x;
    cin>>x;
    int64_t sl=-1,sr=-1,tl=-1,tr=-1;
    auto bs=lower_bound(s.begin(),s.end(),x);
    if(bs!=s.begin())
      sl=x-*(bs-1);
    if(bs!=s.end())
      sr=*bs-x;
    auto bt=lower_bound(t.begin(),t.end(),x);
    if(bt!=t.begin())
      tl=x-*(bt-1);
    if(bt!=t.end())
      tr=*bt-x;
    int64_t u=max({sl,sr,tl,tr});
    sl=(sl==-1?u*3:sl);
    sr=(sr==-1?u*3:sr);
    tl=(tl==-1?u*3:tl);
    tr=(tr==-1?u*3:tr);
    cout<<min({max(sl,tl),sr+tl+min(sr,tl),sl+tr+min(sl,tr),max(sr,tr)})<<endl;
  }
}