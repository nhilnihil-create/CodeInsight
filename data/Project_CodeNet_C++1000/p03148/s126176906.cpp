#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int N,K;
  cin>>N>>K;
  vector<pair<ll,int>> dt(N);
  for(int i=0;i<N;i++){
    cin>>dt.at(i).second>>dt.at(i).first;
  }
  sort(dt.begin(),dt.end());
  reverse(dt.begin(),dt.end());

  set<int> other;
  set<int> l_index;
  set<int> neta;

  ll sum=0;
  for(int i=0;i<K;i++){
    if(neta.count(dt.at(i).second)==0){
      neta.insert(dt.at(i).second);
      l_index.insert(i);
      sum+=dt.at(i).first;
    }else{
      other.insert(i);
      sum+=dt.at(i).first;
    }
  }
  ll ans=sum+(ll)neta.size()*(ll)neta.size();
  for(int i=K;i<N;i++){
    if(other.size()==0){
      break;
    }
    if(neta.count(dt.at(i).second)==0){
      l_index.insert(i);
      neta.insert(dt.at(i).second);
      sum+=dt.at(i).first;
      int k=*rbegin(other);
      sum-=dt.at(k).first;
      other.erase(k);
      ans=max<ll>(ans,sum+(ll)neta.size()*(ll)neta.size());
    }
  }
  cout<<ans<<endl;
}
