#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i < (int)(n);i++)
using namespace std;
bool cmp(pair<int64_t,int64_t> a,pair<int64_t,int64_t> b){
  return a.first + a.second < b.first + b.second;
}
int main(){
  int n;
  cin >> n;
  vector<pair<int64_t,int64_t>> ab(n);
  rep(i,n) cin >> ab.at(i).first >> ab.at(i).second;
  sort(ab.begin(),ab.end(),cmp);
  reverse(ab.begin(),ab.end());
  /*rep(i,n){
    cout << ab.at(i).first << "|" << ab.at(i).second << endl;
  }*/
  int64_t takahashi = 0;
  int64_t aoki = 0;
  rep(i,n){
    if(i % 2 == 0){
      takahashi += ab.at(i).first;
    }else{
      aoki += ab.at(i).second;
    }
  }
  cout << takahashi - aoki << endl;
}
  
  
  