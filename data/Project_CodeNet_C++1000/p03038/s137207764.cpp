#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int>a(n);
  vector<pair<int,int>>cb(m);
  for(int i=0;i<n;i++) cin >> a.at(i);
  for(int i=0;i<m;i++) cin >> cb.at(i).second >> cb.at(i).first;
  sort(a.begin(),a.end());
  sort(cb.begin(),cb.end(),greater());
  int64_t ans=0;
  int p=0;
  for(int i=0;i<n;i++){
    if(cb.at(p).second==0&&p<cb.size()-1) p++;
    if(cb.at(p).second>0&&cb.at(p).first>a.at(i)){
      ans+=cb.at(p).first;
      cb.at(p).second--;
    }else{
      ans+=a.at(i);
    }
  }
  cout << ans << endl;
  return 0;
}