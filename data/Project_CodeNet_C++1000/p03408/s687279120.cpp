#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N,M;
  cin>>N;
  vector<string>red(N);
  rep(i,N){
    cin>>red.at(i);
  }
  cin>>M;
  vector<string>blue(M);
  rep(i,M){
    cin>>blue.at(i);
  }
  int ct=0;
  int cnt=0;
  rep(i,N){
    ct=0;
    rep(j,N){
      if(red.at(i)==red.at(j)){
        ct+=1;
      }
    }
    rep(j,M){
      if(red.at(i)==blue.at(j)){
        ct-=1;
      }
    }
    if(ct>cnt){
      cnt=ct;
    }
    }
  cout<<max(0,cnt);
}
