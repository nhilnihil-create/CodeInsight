#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
using ll = long long;
using lint = long long;
typedef pair<int,int> P;
const lint inf=1e18+7;
const int MOD=1000000007;
signed main(){
  int n;cin>>n;
  map<string,int> memo;
  string buf;cin>>buf;
  memo[buf]+=1;
  char last=buf[buf.size()-1];
  bool flag=true;
  rep(i,n-1){
      cin>>buf;
      if(last!=buf[0]||memo[buf]>0){
          flag=false;
      }
      last=buf[buf.size()-1];
      memo[buf]+=1;
  }
  	if(flag){
          cout<<"Yes"<<endl;
      }
      else{
          cout<<"No"<<endl;
      }
  return 0;
}