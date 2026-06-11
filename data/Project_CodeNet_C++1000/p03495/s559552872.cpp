#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main(){
  int N,K;
  cin>>N>>K;
  vector<int> vec(N);
  rep(i,N) cin>>vec.at(i);
  int count=0;
  sort(vec.begin(),vec.end());
  vector<pair<int,int>> num={make_pair(1,vec.at(0))};
  rep(i,N){
    if(i==0) continue;
    else if(vec.at(i)==vec.at(i-1)) num.at(num.size()-1).first++;
    else num.push_back(make_pair(1,vec.at(i)));
  }
  if(num.size()<K) cout<<0<<endl;
  else{
    sort(num.begin(),num.end());
    int count=0;
    rep(i,num.size()-K) count+=num.at(i).first;
    cout<<count<<endl;
  }
}