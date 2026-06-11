#include <bits/stdc++.h>
using namespace std;

int main(){
  int m=-1;
  int n,nn;
  cin>>n>>nn;
  vector<int> a(n);
  a[0]=nn;
  int ans=0;
  for(int i=1;i<n;i++){
    cin>>a[i];
    if(a[i-1]==a[i]){
      ans++;
      a[i]=m;
      m--;
    }
  }
  cout<<ans<<endl;
}