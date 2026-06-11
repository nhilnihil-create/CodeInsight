#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)


int main(){
  int n,m;
  cin>>n>>m;
  vector<int>a(n);
  vector<int>b(n);
  for(int i=0;i<n;i++){
    cin>>a[i]>>b[i];
  }
  vector<pair<int,int>>AB(n);
  for(int i=0;i<n;i++){
      AB[i]=make_pair(a[i],b[i]);
  }
  sort(AB.begin(),AB.end());
  long long num=0;
  for(int i=0;i<n;i++){
      int buy=min(m,AB[i].second);
      num+=(long long)buy*AB[i].first;
      m-=buy;
  }
  cout<<num<<endl;
}