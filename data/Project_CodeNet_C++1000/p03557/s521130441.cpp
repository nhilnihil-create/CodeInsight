#include <bits/stdc++.h>
using namespace std; 
#define int int64_t
#define itn int
#define fi first
#define se second
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,d,ans=0,sum;
  int h,l;
  vector<int> a,b,c;
  cin>>n;
  for(int i=0;i<n;i++) cin>>d,a.push_back(d);
  for(int i=0;i<n;i++) cin>>d,b.push_back(d);
  for(int i=0;i<n;i++) cin>>d,c.push_back(d);
  sort(a.begin(),a.end()),sort(c.begin(),c.end());
  for(int i=0;i<n;i++){
    h=n,l=-1;
    sum=1;
    while(h-l>1){
      int m=(h+l)/2;
      if(a[m]>=b[i]) h=m;
      else l=m;
    }
    sum*=(h);
    h=n,l=-1;
    while(h-l>1){
      int m=(h+l)/2;
      if(c[m]<=b[i]) l=m;
      else h=m;
    }
    sum*=(n-h);
    ans+=sum;
  }
  cout<<ans<<"\n";
}
