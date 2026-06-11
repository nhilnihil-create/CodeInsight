#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> l(n),r(n);
  for(Int i=0;i<n;i++) cin>>l[i]>>r[i];
  sort(l.begin(),l.end());
  sort(r.begin(),r.end());

  Int ans=0;
  {
    Int res=0,pos=0;
    for(Int i=0;i<n;i++){
      if(r[i]>pos) break;
      res+=abs(pos-r[i]);
      pos=r[i];
      if(pos>l[n-(i+1)]) break;
      res+=abs(l[n-(i+1)]-r[i]);
      pos=l[n-(i+1)];
    }
    chmax(ans,res+abs(pos));
  }
  {
    reverse(l.begin(),l.end());
    reverse(r.begin(),r.end());
    Int res=0,pos=0;
    for(Int i=0;i<n;i++){
      if(l[i]<pos) break;
      res+=abs(pos-l[i]);
      pos=l[i];
      if(pos<r[n-(i+1)]) break;
      res+=abs(r[n-(i+1)]-l[i]);
      pos=r[n-(i+1)];
    }
    chmax(ans,res+abs(pos));
  }
  cout<<ans<<endl;
  return 0;
}
