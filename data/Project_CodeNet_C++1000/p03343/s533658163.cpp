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
const int inf=1000000007;
const int MOD=1000000007;
int n,k,q;
int calc(vector<int> const& a,int mn){
  vector<int> buf;
  vector<int> hoge;
  rep(i,n+1){
    if(a[i]<mn){
      sort(buf.begin(),buf.end());
      if(buf.size()>=k){
        rep(j,buf.size()-k+1){
          hoge.push_back(buf[j]);
        }
      }
      buf.resize(0);
    }
    else{
      buf.push_back(a[i]);
    }
  }
  int res=inf;
  sort(hoge.begin(),hoge.end());
  if(hoge.size()>=q){
    res=hoge[q-1]-hoge[0];
  }
  return res;
}
signed main(){
  cin>>n>>k>>q;
  vector<int> a(n);
  rep(i,n)cin>>a[i];
  int res=inf;
  vector<int> num(a);
  a.push_back(0);
  sort(num.begin(),num.end());
  rep(i,n){
    res=min(res,calc(a,num[i]));
  }
  //if(res==inf)res=-1;
  cout<<res<<"\n";
  return 0;
}
