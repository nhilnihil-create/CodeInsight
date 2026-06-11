#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin>>n;
  pair<int,int> red[n];
  pair<int,int> blue[n];
  for(int i=0;i<n;i++) cin>>red[i].first>>red[i].second;
  for(int i=0;i<n;i++) cin>>blue[i].first>>blue[i].second;
  sort(blue,blue+n);
  int ans=0;
  bool c[n];
  for(int i=0;i<n;i++) c[i]=false;
  for(int i=0;i<n;i++){
    int temp_y=-1;
    int temp=-1;
    for(int j=0;j<n;j++){
      if(c[j]) continue;
      if(red[j].first<blue[i].first && red[j].second<blue[i].second){
        temp_y=max(temp_y,red[j].second);
        if(temp_y==red[j].second) temp=j;
      }
    }
    if(temp!=-1){
      ans++;
      c[temp]=true;
    }
  }
  cout<<ans<<endl;
  return 0;
}