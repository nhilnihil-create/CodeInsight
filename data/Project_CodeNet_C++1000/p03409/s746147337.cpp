#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<vector<int>> a(n,vector<int>(2));
  vector<vector<int>> b(n,vector<int>(2));
  for(int i=0;i<n;i++){
    cin>>a.at(i).at(0);
    cin>>a.at(i).at(1);
  }
  for(int i=0;i<n;i++){
    cin>>b.at(i).at(0);
    cin>>b.at(i).at(1);
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  int ans=0;
  for(int i=0;i<n;i++){
    int p=-1;
    int cur=-1;
    for(int j=0;j<n;j++){
      if(a.at(j).at(0)<b.at(i).at(0)){
        if(a.at(j).at(1)<b.at(i).at(1)){
          if(cur<a.at(j).at(1)){
            p=j;
            cur=a.at(j).at(1);
          }
        }
      }
      else{
        break;
      }
    }
    if(p!=-1){
      ans++;
      a.at(p).at(1)=114514;
    }
  }
  cout<<ans<<endl;
}