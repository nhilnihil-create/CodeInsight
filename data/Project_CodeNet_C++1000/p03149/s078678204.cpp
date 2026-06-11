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
//#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
const int inf=1000000007;
const int MOD=1000000007;
signed main(){
  vector<int> a(4);
  rep(i,4)cin>>a[i];
  sort(ALL(a));
  bool flag=false;
  if(a[0]==1&&a[1]==4){
    if(a[2]==7&&a[3]==9){
      flag=true;
    }
  }
  if(flag){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
  return 0;
}
