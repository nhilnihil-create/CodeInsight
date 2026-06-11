#include<bits/stdc++.h>
using namespace std;


int main(){
  int n,i;
  cin >> n;
  vector<int> a(n);
  for(i=0;i<n;++i){
    cin >> a[i];
  }
  int ans=0;
  for(i=0;i<n-1;++i){
    if(a[i]==a[i+1]){
      ans++;
      if(a[i]==a[i+2] && i<n-2){
        i++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
