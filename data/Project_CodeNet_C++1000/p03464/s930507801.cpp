#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
//const int inf=1000000007;
const int MOD=1000000007;
signed main(){
  int k;cin>>k;
  vector<int> a(k);
  rep(i,k)cin>>a[i];
  bool flag=true;int inf=2;int sup=2;
  for(int i=k-1;i>=0;i--){
    if(a[i]<=sup){
      int m=(sup)/a[i];
      int n=(inf-1)/a[i]+1;
      if(m*a[i]<inf||n*a[i]>sup)flag=false;
      inf=a[i]*n;
      sup=a[i]*(m+1)-1;
    }
    else{
      flag=false;
      break;
    }
  }
  if(flag){
    cout<<inf<<" "<<sup<<endl;
  }
  else{
    cout<<-1<<endl;
  }
  return 0;
}
