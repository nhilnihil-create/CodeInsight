#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> d(n);
  for(int i=0;i<n;i++){
      cin>>d[i];
  }
  sort(d.begin(),d.end());
  int ans=0;
  for(int i=1;i<n;i++){
      if(d[i]>d[i-1]) ans++;
  }
  cout<<ans+1<<endl;
}