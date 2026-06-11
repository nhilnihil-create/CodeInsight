#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define prin(arg) std::cout<<arg<<"\n"
#define prin2(arg1,arg2) std::cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) std::memset(arg,n,sizeof(arg))
#define mp std::make_pair
#define pb push_back
using std::cin;
typedef long long ll;
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::set<int> si;
typedef std::string str;
const int INF=1e+9;
const ll INFLL=1e+17;
const ll MOD=1e+9+7;
str s;
int main(){
  cin>>s;
  int ss=s.size();
  int ac=0,bc=0,cc=0;
  rep(i,ss){
    if(s[i]=='a') ac++;
    else if(s[i]=='b') bc++;
    else cc++;
  }
  int dis1=std::abs(ac-bc);
  int dis2=std::abs(ac-cc);
  int dis3=std::abs(cc-bc);    
  if(dis1<2&&dis2<2&&dis3<2) prin("YES");
  else prin("NO");
  
  return 0;
}
