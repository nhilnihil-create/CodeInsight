#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll q;
  cin >> q;
  vector<ll> l(q),r(q);
  rep(i,q){
    cin >> l.at(i) >> r.at(i);
  }
  vector<bool> is(100001,false);
  vector<ll> ans(100001,0);
  for(int i=3;i<=100000;i+=2){
    ll cp=i,cp1=(i+1)/2;
    bool no=true;
    for(int k=2;k*k<=i;k++){
      if(cp%k==0){
        no=false;
      }
    }
    for(int k=2;k*k<=cp1;k++){
      if(cp1%k==0){
        no=false;
      }
    }
    if(no){
      ans.at(i)=ans.at(i-2)+1;
      is.at(i)=true;
    }else{
      ans.at(i)=ans.at(i-2);
    }
  }
  rep(i,q){
    int as=ans.at(r.at(i))-ans.at(l.at(i));
    if(is.at(l.at(i))){
      as++;
    }
    cout << as << endl;
  }
}