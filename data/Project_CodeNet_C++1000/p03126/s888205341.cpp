#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<int> cnt(m);
  for(int i=0;i<n;i++){
      int k;
      cin>>k;
      for(int i=0;i<k;i++){
          int a;
          cin>>a;
          a--;
          cnt[a]++;
      }
  }
  int ans=0;
  for(int i=0;i<m;i++){
      if(cnt[i]==n) ans++;
  }
  cout<<ans<<endl;
}