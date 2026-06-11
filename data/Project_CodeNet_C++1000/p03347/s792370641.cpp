#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(!i){
      if(a[i]){
        cout << -1 << endl;
        return 0;
      }
    }
    else{
      if(a[i-1]<a[i]){
        if(a[i-1]+1!=a[i]){
          cout << -1 << endl;
          return 0;
        }
      }
    }
  }
  long long ans=0;
  for(int i=1;i<n;i++){
    if(a[i-1]+1==a[i]){
      ans++;
    }
    else{
      ans+=a[i];
    }
  }
  cout << ans << endl;
}