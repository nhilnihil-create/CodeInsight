#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n;
  cin>>n;
  map<int,int> odd,even;
  rep(i,n){
    int v; cin>>v;
    if(i%2==0) odd[v]++;
    else even[v]++;
  }
  int cnt_odd1=0, cnt_odd2=0, cnt_even1=0, cnt_even2=0;
  int num_odd1,num_even1;
  for(auto x : odd){
    if(cnt_odd1<x.second){
      cnt_odd2=cnt_odd1;
      cnt_odd1=x.second;
      num_odd1=x.first;
    }else if(cnt_odd2<x.second){
      cnt_odd2=x.second;
    }
  }
  for(auto x : even){
    if(cnt_even1<x.second){
      cnt_even2=cnt_even1;
      cnt_even1=x.second;
      num_even1=x.first;
    }else if(cnt_even2<x.second){
      cnt_even2=x.second;
    }
  }
  int ans=0;
  if(num_odd1==num_even1){
    ans=min(n-cnt_odd1-cnt_even2,n-cnt_odd2-cnt_even1);
  }else{
    ans=n-cnt_odd1-cnt_even1;
  }
  cout<<ans<<endl;
}
