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
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
int l,r,u,d,h,w;
bool flag;
void moveT(char c){
  if(c=='L'){
    l++;
  }
  else if(c=='R'){
    r--;
  }
  else if(c=='U'){
    u++;
  }
  else if(c=='D'){
    d--;
  }
  if(l==w||r==1){
    flag=true;
  }
  if(u==h||d==1){
    flag=true;
  }
}
void moveA(char c){
  if(c=='R'&&l>0){
    l--;
  }
  else if(c=='L'&&r<w+1){
    r++;
  }
  else if(c=='D'&&u>0){
    u--;
  }
  else if(c=='U'&&d<h+1){
    d++;
  }
}
signed main(){
  int n;cin>>h>>w>>n;
  int sr,sc;cin>>sr>>sc;
  string s,t;cin>>s>>t;
  l=0;u=0;r=w+1;d=h+1;
  flag=false;
  moveT(s[n-1]);
  //printf("(l,r,u,d)= %d %d %d %d\n",l,r,u,d);
  for(int i=n-2;i>=0;i--){
    moveA(t[i]);
    //printf("(l,r,u,d)= %d %d %d %d\n",l,r,u,d);
    moveT(s[i]);
    //printf("(l,r,u,d)= %d %d %d %d\n",l,r,u,d);
  }
  if(sr<=u||sr>=d){
    flag=true;
  }
  if(sc<=l||sc>=r){
    flag=true;
  }
	if(!flag){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
  return 0;
}
