#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
int main(){
  ll n;cin>>n;
  ll l[n],r[n];
  vector<pll> v,w;
  for(int i=0;i<n;i++){
    cin>>l[i]>>r[i];
    v.push_back(make_pair(l[i],i));
    w.push_back(make_pair(r[i],i));
  }
  sort(v.begin(),v.end(),greater<pll>());
  sort(w.begin(),w.end());
  ll nl=0,nr=0;
  ll ans=0;
  bool used[n];
  fill(used,used+n,false);
  int c=0;
  ll now=0;
  for(;;){
   if(c==0){
     while(nl<n&&used[v[nl].second])nl++;
     if(nl==n)break;
     c=1;
     ll y=v[nl].second;
     if(l[y]<=now&&r[y]>=now){
       used[y]=true;
       continue;
     }
     else{
       ans+=abs(l[y]-now);
       now=l[y];
       used[y]=true;
       continue;
     }
   }
    else{
      while(nr<n&&used[w[nr].second])nr++;
      if(nr==n)break;
      c=0;
      ll y=w[nr].second;
      if(l[y]<=now&&r[y]>=now){
        used[y]=true;
        continue;
      }
      else{
        ans+=abs(r[y]-now);
        now=r[y];
        used[y]=true;
        continue;
      }
    }
  }
  ans+=abs(now);
  fill(used,used+n,false);
  ll ans2=0;
  nl=0;nr=0;
  c=1;
  now=0;
  for(;;){
   if(c==0){
     while(nl<n&&used[v[nl].second])nl++;
     if(nl==n)break;
     c=1;
     ll y=v[nl].second;
     if(l[y]<=now&&r[y]>=now){
       used[y]=true;
       continue;
     }
     else{
       ans2+=abs(l[y]-now);
       now=l[y];
       used[y]=true;
       continue;
     }
   }
    else{
      while(nr<n&&used[w[nr].second])nr++;
      if(nr==n)break;
      c=0;
      ll y=w[nr].second;
      if(l[y]<=now&&r[y]>=now){
        used[y]=true;
        continue;
      }
      else{
        ans2+=abs(r[y]-now);
        now=r[y];
        used[y]=true;
        continue;
      }
    }
  }
  ans2+=abs(now);
  cout<<max(ans,ans2)<<endl;
}