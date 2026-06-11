#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,x;
  cin>>n>>x;
  vector<int>a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  sort(a.begin(),a.end());
  int ans=0;
  while(x>0 && ans<=n-1){
    if(x-a[ans]==0){
      ans++;
      break;
    }
    else if(x-a[ans]>0 && ans==n-1) break;
    else if(x-a[ans]>0){
      x-=a[ans];
      ans++;
    }
    else break;
  }
  cout<<ans<<endl;
}