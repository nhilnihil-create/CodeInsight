#include <bits/stdc++.h>

using namespace std;

using P = pair<int,int>;

vector<P> func(vector<int> array){
  map<int,int> m;
  for(auto&i:array){
    ++m[i];
  }
  vector<P> res;
  for(auto&i:m){
    res.emplace_back(i.second,i.first);
  }
  sort(res.begin(),res.end(),greater<P>());
  res.emplace_back(0,0);
  return res;
}

int main(){
  int n;
  cin >> n;
  vector<int> array;
  vector<int> array1;
  vector<int> array2;
  for(int i=0;i<n;++i){
    int d;
    cin >> d;
    array.emplace_back(d);
    if(i&1){
      array1.emplace_back(d);
    }else{
      array2.emplace_back(d);
    }
  }
  vector<P> ans1 = func(array1);
  vector<P> ans2 = func(array2);
  int ans = n;
  for(int i=0;i<2;++i){
    for(int j=0;j<2;++j){
      if(ans1[i].second==ans2[j].second)continue;
      ans = min(ans,n-ans1[i].first-ans2[j].first);
    }
  }
  cout << ans << endl;
  return 0;
}
