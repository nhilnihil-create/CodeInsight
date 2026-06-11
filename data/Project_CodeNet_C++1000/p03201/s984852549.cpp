#include<bits/stdc++.h>
using namespace std;
#define int long
main(){
  int n,r=0;
  cin>>n;
  vector<int> a(n);
  map<int,int> m;
  for(auto &i:a)cin>>i,++m[i];
  sort(a.begin(),a.end());
  auto f = [](int x){
    ++x;
    if(x<=0)return 0l;
    if((x&(x-1))==0)return x;
    int res=1;
    while(x>0)res<<=1,x>>=1;
    return res;
  };
  for(int i=n-1;i>=0;--i){
    int d=f(a[i])-a[i];
    if(m[a[i]]>0&&m[d]>0){
      if(a[i]!=d)++r,--m[a[i]],--m[d];
      else if(m[d]>1)++r,m[d]-=2;
    }
  }
  cout<<r;
}