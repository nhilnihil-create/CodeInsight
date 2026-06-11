#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n; cin>>n;
  vector<int> h(n);
  int max_h=0;
  rep(i,n){
    cin>>h[i];
    max_h=max(max_h,h[i]);
  }
  int cnt=0;
  for(int mark=1; mark<=max_h; mark++){
    bool renzoku=0;
    rep(i,n){
      if(!renzoku && h[i]>=mark)cnt++;
      if(h[i]<mark){
        renzoku=0;
      }
      else if(h[i]>=mark)renzoku=1;
    }
  }
  cout<<cnt<<endl;
}

