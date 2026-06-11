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
#define ll long long
#define lint long long
typedef pair<int,int> P;
const lint inf=1e18+7;
const int MOD=1000000007;
signed main(){
  string s;cin>>s;
  int n=s.length();
  if(s[n-1]=='1'){
    cout<<-1<<endl;
    return 0;
  }
  if(s[0]=='0'){
    cout<<-1<<endl;
    return 0;
  }
  rep(i,n/2){
    if(s[i]!=s[n-2-i]){
      cout<<-1<<endl;
      return 0;
    }
  }
  int cur=1;
  int nxt=2;
  for(int i=0;i<n-1;++i){
    if(i>=n/2){
      s[i]='0';
    }
    if(s[i]=='0'){
      printf("%lld %lld\n",cur,nxt);
      ++nxt;
    }
    else{
      printf("%lld %lld\n",cur,nxt);
      cur=nxt;
      ++nxt;
    }
  }
  int no=nxt-1;
  while(nxt<=n){
    printf("%lld %lld\n",no,nxt);
    ++nxt;
  }
  return 0;
}
//111010011111100101110