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
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
int h,w,n,sr,sc;
string s,t;
int l,r,u,d;
void moveT(char buf){
  if(buf=='L')++l;
  if(buf=='R')--r;
  if(buf=='U')++u;
  if(buf=='D')--d;
}
void moveA(char buf){
  if(buf=='L'&&r<w+1)++r;
  if(buf=='R'&&l>0)--l;
  if(buf=='U'&&d<h+1)++d;
  if(buf=='D'&&u>0)--u;
}
bool check(){
  bool res=false;
  if(l>=w||r<=1)res=true;
  if(u>=h||d<=1)res=true;
  return res;
}
signed main(){
  cin>>h>>w>>n;
  cin>>sr>>sc;
  cin>>s;
  cin>>t;
  l=0;r=w+1;u=0;d=h+1;
  bool flag=false;
  moveT(s[n-1]);
  flag=check();
  for(int i=n-2;i>=0;--i){
    moveA(t[i]);
    moveT(s[i]);
    flag=check();
    if(flag)break;
  }
  if(sr<=u||sr>=d)flag=true;
  if(sc<=l||sc>=r)flag=true;
	if(!flag){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
  return 0;
}
