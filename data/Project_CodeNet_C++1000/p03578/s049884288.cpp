#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >>n;
  vector<int>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  map<int,int>mp;
  for(int x:a){
    if(mp.count(x)){
      mp.at(x)++;
    }else{
      mp[x]=1;
    }
  }
  int m;
  cin>>m;
  vector<int>b(m);
  for(int i=0;i<m;i++)cin>>b[i];
  for(int i=0;i<m;i++){
    if(mp.count(b[i])){
      mp.at(b[i])--;
      if(mp.at(b[i])<0){
        cout<<"NO"<<endl;
        return 0;
      }
    }else{
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
  return 0;
}
