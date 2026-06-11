#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<utility>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define prin(arg) std::cout<<arg<<"\n"
#define prin2(arg1,arg2) std::cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) std::memset(arg,n,sizeof(arg))
using std::cin;
typedef long long ll;
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
const int INF=1e+9;
const ll INFLL=1e+17;
std::string S;
int solve(){
  int res1=INF,ss=S.size();
  rep(i,ss){
    if(S[i]=='1'){
      int temp=std::max(std::max(i,ss-1-i),std::min(i+1,ss-i));
      res1=std::min(res1,temp);
    }
  }
  int res2=INF;
  rep(i,ss){
    if(S[i]=='0') S[i]='1';
    else S[i]='0';
  }
  rep(i,ss){
    if(S[i]=='1'){
      int temp=std::max(std::max(i,ss-1-i),std::min(i+1,ss-i));
      res2=std::min(res2,temp);
    }
  }  
  int res=std::max(res1,res2);
  if(res==INF) res=ss;
  return res;
}
int main(){
  cin>>S;
  prin(solve());
  return 0;
}
