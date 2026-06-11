#include<bits/stdc++.h>
using namespace std;


int main(){
  int n;
  cin >> n;
  vector<int> a(n+1);
  for(int i=1;i<=n;++i){
    int p;
    cin >> p;
    a[p]=i;
  }
  int ans=0;
  int cnt=1;
  for(int i=1;i<=n;++i){
    if(a[i]<a[i+1])cnt++;
    else{
      ans=max(ans,cnt);
      cnt=1;
    }
  }
  ans=max(ans,cnt);
  cout << n-ans << endl;
  return 0;
}
