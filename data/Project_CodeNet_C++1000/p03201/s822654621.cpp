#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin >> n;
  vector<int> a(n),c(32);
  c[0]=1;
  for(int i=1;i<32;i++){
    c[i]=c[i-1]*2;
  }
  map<int,int> mp;
  for(int i=0;i<n;i++){
    cin >> a[i];
    mp[a[i]]++;
  }
  int ans=0;
  sort(a.begin(),a.end(),greater<int>());
  for(int i=0;i<n;i++){
    for(int j=31;j>=0;j--){
      if(c[j]>a[i]&&mp[a[i]]&&mp[c[j]-a[i]]){
        if(a[i]==c[j]-a[i]){
          if(mp[a[i]]>=2){
            ans++;
            mp[a[i]]-=2;
          }
        }
        else{
          ans++;
          mp[a[i]]--;
          mp[c[j]-a[i]]--;
        }
      }
    }
  }
  cout << ans << endl;
}