#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template<typename T>
vector<T> compress(vector<T> v){
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  return v;
}

//INSERT ABOVE HERE
signed main(){
  Int n,k,q;
  cin>>n>>k>>q;
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];

  auto c=compress(a);

  auto check=
    [&](Int d)->Int{
      Int res=0;
      for(Int y:c){
        Int tmp=0,len=0,cnt=0;
        for(Int i=0;i<n;i++){
          if(a[i]<y){
            tmp+=max(0LL,min(len-(k-1),cnt));
            len=cnt=0;
            continue;
          }
          len++;
          if(a[i]<=y+d) cnt++;
        }
        tmp+=max(0LL,min(len-(k-1),cnt));
        chmax(res,tmp);
      }
      return res>=q;
    };

  Int l=-1,r=2e9+1;
  while(l+1<r){
    Int m=(l+r)>>1;
    if(check(m)) r=m;
    else l=m;
  }
  cout<<r<<endl;
  return 0;
}
