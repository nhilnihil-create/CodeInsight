#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  vector<int>x(n);
  for(int i=0;i<n;i++){
    int y;
    cin>>y;
    x[y-1]++;
  }
  sort(x.begin(),x.end());
  reverse(x.begin(),x.end());
  int ans=0;
  for(int j=0;j<n-k;j++){
  ans+=x[n-1-j];
  x.pop_back();
  }
  cout<<ans<<endl;
}