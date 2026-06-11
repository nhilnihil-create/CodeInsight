#include<bits/stdc++.h>
using namespace std;

bool rev(const pair<float,int>&a,const pair<float,int>&b){
  return a.first<b.first;
}

int main(){
  int n;
  float t,a;
  cin>>n>>t>>a;
  float arr[n];
  for(int i=0;i<n;++i){
    cin>>arr[i];
  }
  vector<pair<float,int>>v;
  int i=0;
  for (auto x : arr){
    float ans = t-x*0.006;
    ans = abs(ans-a);
    v.push_back({ans,i});
    ++i;
  }
  sort(v.begin(),v.end(),rev);
  for (auto x : v){
      cout<<x.second+1;
      break;
  }
  
}
 