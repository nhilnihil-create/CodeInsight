#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w,n;
  cin>>h>>w>>n;
  map<pair<int,int>,int> m;
  vector<int> a(h+1,200010);
  for(int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    m[make_pair(x,y)]=1;
    a[x]=min(a[x],y);
  }
  int c=0;
  for(int i=2;i<=h;i++){
    if(a[i]<i-c){
      cout<<i-1;
      return 0;
    }
    if(m[make_pair(i,i-c)]==1){
      c++;
    }
  }
  cout<<h;
}