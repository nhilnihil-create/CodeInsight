#include <bits/stdc++.h>
#define ll long long
using namespace std;

int digit(int x){
  int y=0;
  while(x>0){
    y++;
    x/=10;
  }
  return y;
}

int main(){
  int n,m;
  cin>>n>>m;
  vector<pair<int,ll>> vec(m);
  vector<pair<int,ll>> vecb(m);
  for(int i=0;i<m;i++){
    int j;
    ll k;
    cin>>j>>k;
    vec[i]=make_pair(j,k);
    vecb[i]=vec[i];
  }
  sort(vecb.begin(),vecb.end());
  map<pair<int,ll>,int> ma;
  for(int i=0;i<m;i++){
    if(i==0){
      ma[vecb[i]]=1;
    }
    else{
      if(vecb[i].first==vecb[i-1].first){
        ma[vecb[i]]=ma[vecb[i-1]]+1;
      }
      else{
        ma[vecb[i]]=1;
      }
    }
  }
  for(int i=0;i<m;i++){
    for(int j=0;j<6-digit(vec[i].first);j++){
      cout<<0;
    }
    cout<<vec[i].first;
    for(int j=0;j<6-digit(ma[vec[i]]);j++){
      cout<<0;
    }
    cout<<ma[vec[i]]<<endl;
  }
}