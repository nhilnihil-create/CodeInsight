#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)

bool compare_by_greater_y(pair<int,int>a, pair<int,int>b){
  if(a.second!=b.second) return a.second>b.second;
  else return a.first>b.first;
}

int main(){
  int n,ans=0;
  pair<int,int> r[100],b[100];
  bool rf[100];
  cin>>n;
 
  REP(i,n){
    int x,y;cin>>x>>y;
    r[i]=make_pair(x,y);
    rf[i]=0;
  }
  sort(r,r+n,compare_by_greater_y);  

  REP(i,n){
    int x,y;cin>>x>>y;
    b[i]=make_pair(x,y);
  }
  sort(b,b+n);

  REP(i,n){
    REP(j,n){
      if(!rf[j]&&r[j].first<b[i].first&&r[j].second<b[i].second){
        ans++;
        rf[j]=1;
        break;
      }
    }
  }

  cout<<ans;
}