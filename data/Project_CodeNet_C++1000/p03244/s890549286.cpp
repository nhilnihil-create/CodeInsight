#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  map<int,int> mp1,mp2;
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    if(i%2){
      mp1[a]++;
    } else {
      mp2[a]++;
    }
  }
  vector <pair<int,int>> a,b;
  for(auto it:mp1){
    a.emplace_back(it.second,it.first);
  }
  for(auto it:mp2){
    b.emplace_back(it.second,it.first);
  }
  sort(a.rbegin(),a.rend());
  sort(b.rbegin(),b.rend());
  if(a[0].second!=b[0].second){
    cout << n-a[0].first-b[0].first << endl;
  } else {
    cout << n-max(a[0].first+b[1].first,a[1].first+b[0].first) << endl;
  }
  return 0;
}
