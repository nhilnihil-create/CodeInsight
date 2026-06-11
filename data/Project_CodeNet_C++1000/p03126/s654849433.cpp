#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,x;
  cin >> n >> x;
  map<int,int>suki;
  int m;
  for(int i=0;i<n;i++){
    cin >> m;
    int s;
    for(int j=0;j<m;j++){
      cin >> s;
      suki[s]++;
    }
  }
  int ans=0;
  for(auto i:suki){
    if(i.second==n)
      ans++;
  }
  cout << ans << endl;
  return 0;
}