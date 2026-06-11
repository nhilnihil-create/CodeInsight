#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
int main(){ 
  ll n,max_i,min_i,ma_n=0,mi_n=0;
  bool is_p=false;
  vector<pair<ll,ll>> ans;
  cin >> n;
  ll a[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(a[i]>0){
      ma_n=max(a[i],ma_n);
    }else{
      mi_n=min(a[i],mi_n);
    }
  }
  if(ma_n>abs(mi_n)){
    is_p=true;
  }else{
    is_p=false;
  }
  if(is_p==true){
    max_i=0;
    for(int i=0;i<n;i++){
      if(a[max_i]<a[i]){
        max_i=i;
      }
    }
    ans.push_back(make_pair(0,max_i));
    ans.push_back(make_pair(0,max_i));
    for(int i=1;i<n;i++){
      ans.push_back(make_pair(i,i-1));
      ans.push_back(make_pair(i,i-1));
    }
  }else{
    min_i=0;
    for(int i=0;i<n;i++){
      if(a[min_i]>a[i]){
        min_i=i;
      }
    }
    ans.push_back(make_pair(n-1,min_i));
    for(int i=n-2;i>=0;i--){
      ans.push_back(make_pair(i,i+1));
      ans.push_back(make_pair(i,i+1));
    }
  }
  cout << ans.size()<<endl;
  for(int i=0;i<ans.size();i++){
    cout << ans[i].second+1<<" "<<ans[i].first+1<<endl;
  }
  /*
  for(int i=0;i<n;i++) cout << a[i]<<" ";
  cout << endl;
  */
}
