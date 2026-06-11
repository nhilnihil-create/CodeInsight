#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  
  int ans=0;
  
  for(int i=0;i<n;i++){
    while(a[i]){
      int p=0;
      for(int j=i;j<n;j++){
        if(a[j]){
          p++;
          a[j]--;
        }
        else break;
      }
      if(p) ans++;
    }
  }
  
  cout << ans << endl;
  
}