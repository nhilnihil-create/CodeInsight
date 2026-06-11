#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,x;
  cin>>n>>x;
  vector<int> m(n);
  for(int i=0;i<n;i++){
    cin>>m[i];
  }
  int ans=0;
  for(int i=0;i<n;i++){
    ans++;
    x-=m[i];
  }
  sort(m.begin(),m.end());
  while(m[0]<=x){
    ans++;
    x-=m[0];
  }
  cout<<ans<<endl;
}