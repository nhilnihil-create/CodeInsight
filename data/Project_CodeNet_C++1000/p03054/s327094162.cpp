#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int h,w,n,y,x;
  string s,t;
  cin>>h>>w>>n>>y>>x>>s>>t;
  int u=1,d=h,l=1,r=w;
  for(int i=n-1; i>=0; --i){
    if(t[i]=='U')d=min(h,d+1);
    if(t[i]=='D')u=max(1,u-1);
    if(t[i]=='L')r=min(w,r+1);
    if(t[i]=='R')l=max(1,l-1);
    if(s[i]=='U')u++;
    if(s[i]=='D')d--;
    if(s[i]=='L')l++;
    if(s[i]=='R')r--;
    if(u>d||l>r){cout<<"NO"<<endl; return 0;}
  }
  if(u<=y&&y<=d&&l<=x&&x<=r)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}