#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin >> n;
  vector<int> a(n);
  vector<pair<int,int>> ans;
  int l=1e7,h=-1e7;
  int li,ri;
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(l>a[i]){
      l=a[i];
      li=i;
    }
    if(h<a[i]){
      h=a[i];
      ri=i;
    }
  }
  if(abs(h)>=abs(l)){
    if(l<0){
      for(int i=0;i<n;i++){
        if(a[i]<0){
          ans.push_back(make_pair(ri+1,i+1));
          a[i]+=a[ri];
        }
      }
    }
    for(int i=0;i<n-1;i++){
      if(a[i]>a[i+1]){
        ans.push_back(make_pair(i+1,i+1+1));
        a[i+1]+=a[i];
      }
    }
  }
  else{
    if(h>0){
      for(int i=0;i<n;i++){
        if(a[i]>0){
          ans.push_back(make_pair(li+1,i+1));
          a[i]+=a[li];
        }
      }
    }
    for(int i=n-1;i>0;i--){
      if(a[i-1]>a[i]){
        ans.push_back(make_pair(i+1,i));
        a[i-1]+=a[i];
      }
    }
  }
  cout << ans.size() << endl;
  for(int i=0;i<ans.size();i++){
    cout << ans[i].first << " " << ans[i].second << endl;
  }
}