#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  if(n==1){
      cout << 0 << endl;
      return 0;
  }
  vector<pair<int,int>> p(n);
  for(int i=0;i<n;i++){
    cin >> p[i].first;
    p[i].second=i;
  }
  int ans=-1;
  int cnt=1;
  sort(p.begin(),p.end());
  for(int i=0;i<n-1;i++){
      if(p[i+1].second>p[i].second){
          cnt++;
        if(i==n-2){
          ans=max(ans,cnt);
        }
      }
      else{
          ans=max(ans,cnt);
          cnt=1;
      }
  }
  cout << n-ans << endl;
}
