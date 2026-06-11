#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<vector<int>>miti(2,vector<int>(n));
  for(int i=0;i<n;i++)
    cin >> miti.at(0).at(i);
  for(int i=0;i<n;i++)
    cin >> miti.at(1).at(i);
  int ans=0,nw;
  for(int i=0;i<n;i++){
    nw=0;
    for(int j=0;j<n;j++){
      if(j<=i)
        nw+=miti.at(0).at(j);
      if(j>=i)
        nw+=miti.at(1).at(j);
    }
    ans=max(ans,nw);
  }
  cout << ans << endl;
  return 0;
}