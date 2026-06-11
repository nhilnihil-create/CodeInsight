#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >>n;
  map<int,int>mp;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    mp[x]++;
  }
  int m;
  cin>>m;
  for(int i=0;i<m;i++){
    int x;
    cin>>x;
    if(mp[x]>=1)mp[x]--;
    else{
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
  return 0;
}

