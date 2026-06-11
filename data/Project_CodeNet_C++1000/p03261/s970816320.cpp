#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin>>n;
  vector<string> w(n);
  rep(i,n){
    cin>>w[i];
  }
  bool ans=true;
  map<string,int> k;
  rep(i,n){
    if(k.count(w[i])){
      ans=false;
    }
    k[w[i]]=0;
  }
  rep(i,n-1){
    string las, fir;
    las=w[i].substr(w[i].size()-1,1);
    fir=w[i+1].substr(0,1);
    if(las!=fir){
      ans=false;
    }
  }
  if(ans){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}