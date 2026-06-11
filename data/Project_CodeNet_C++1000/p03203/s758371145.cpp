#include "bits/stdc++.h"
using namespace std;
#define int long long
int mod=1e9+7;

signed main(){
  int h,w,n;
  cin>>h>>w>>n;
  vector<pair<int,int> > xy(n);
  for(int i=0;i<n;i++){
    cin>>xy[i].first>>xy[i].second;
  }
  sort(xy.begin(),xy.end());

  int cn=0;
  int f=-1;
  for(int i=0;i<n;i++){
    int x=xy[i].first;
    int y=xy[i].second;
    if(f<x&&x==y+cn){
      cn++;
      f=x;
    }else if(x>y+cn){
      cout<<x-1<<endl;
      return 0;
    }
  }
  cout<<h<<endl;
}
