#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
int main(){
int h,w,d,a;
cin>>h>>w>>d;
vector<pair<int,int>> vp(h*w+1);
rep(i,h)
  rep(j,w){
     cin>>a;
     vp[a].first=i;
     vp[a].second=j;
  }
  int v[h*w+1]={};
  for(int i=1;i<=d;i++){
     int f=vp[i].first,s=vp[i].second,b=0;
     for(int j=i+d;j<=h*w;j+=d){
        v[j]=abs(vp[j].first-f)+abs(vp[j].second-s)+b;
        b=v[j];
        f=vp[j].first;
        s=vp[j].second; 
     }
  }
  int q,l,r;
  cin>>q;
  rep(i,q){
     cin>>l>>r;
     cout<<v[r]-v[l]<<endl; 
  }
  return 0;
}