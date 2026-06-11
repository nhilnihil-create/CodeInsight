#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n,m;
  cin>>n>>m;
  vector<pair<long long,long long>>mise(n);
  for(long long i=0;i<n;i++){
    cin>>mise[i].first>>mise[i].second;
  }
  sort(mise.begin(),mise.end());
  long long sum=0;
  long long kazu=0;
  for(int i=0;i<n;i++){
    if(kazu<m){
      if(m-kazu>=mise[i].second){
        sum+=mise[i].second*mise[i].first;
        kazu+=mise[i].second;
      }else{
        sum+=(m-kazu)*mise[i].first;
        kazu+=m-kazu;
      } 
    }
    if(kazu==m)break;
  }
  cout<<sum<<endl;
  return 0;
}