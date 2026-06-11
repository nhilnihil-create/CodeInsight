#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t n,m;
  cin >> n >> m;
  vector<pair<int64_t,int64_t>>mise(n);
  for(int i=0;i<n;i++)
    cin >> mise.at(i).first >> mise.at(i).second;
  sort(mise.begin(),mise.end());
  int64_t ans=0,s=0;
  {int64_t i=0;
  while(s<m){
    if(m-s<mise.at(i).second){
      ans+=mise.at(i).first*(m-s);
      s+=m-s;
    }else{
      ans+=mise.at(i).second*mise.at(i).first;
      s+=mise.at(i).second;
    }
    i++;
  }
  }
  cout << ans << endl;
  return 0;
}