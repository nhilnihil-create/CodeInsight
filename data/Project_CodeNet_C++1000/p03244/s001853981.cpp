#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

const ll MOD=1000000007;

int  main(){
  int n;
  cin>>n;
  vector<pair<int,int>>K;
  vector<pair<int,int>>G;
  vector<int>KI(n/2);
  vector<int>GU(n/2);
  for(int i=0;i<n/2;i++){
    cin>>KI.at(i)>>GU.at(i);
  }
  sort(KI.begin(),KI.end());
  sort(GU.begin(),GU.end());
  K.push_back(make_pair(1,KI.at(0)));
  G.push_back(make_pair(1,GU.at(0)));
  for(int i=1;i<n/2;i++){
    if(K.at(K.size()-1).second==KI.at(i)){
      K.at(K.size()-1).first=K.at(K.size()-1).first+1;
    }
    else{
      K.push_back(make_pair(1,KI.at(i)));
    }
  }
  for(int i=1;i<n/2;i++){
    if(G.at(G.size()-1).second==GU.at(i)){
      G.at(G.size()-1).first=G.at(G.size()-1).first+1;
    }
    else{
      G.push_back(make_pair(1,GU.at(i)));
    }
  }
  K.push_back(make_pair(0,-1));
  G.push_back(make_pair(0,-1));
  sort(K.begin(),K.end());
  reverse(K.begin(),K.end());
  sort(G.begin(),G.end());
  reverse(G.begin(),G.end());
  if(K.at(0).second==G.at(0).second){
    cout<<n-max(K.at(0).first+G.at(1).first,K.at(1).first+G.at(0).first)<<endl;
  }
  else{
    cout<<n-K.at(0).first-G.at(0).first<<endl;
  }
}