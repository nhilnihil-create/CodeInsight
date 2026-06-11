#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,p;
  string s;
  cin >> n;
  vector<pair<pair<string, int>, int>> rest(n);
  for(auto i=0;i<n;i++){
    cin>>s>>p;
    rest[i].first.first=s;
    rest[i].first.second=-p;
    rest[i].second=i+1;
  }
  sort(rest.begin(),rest.end());
  for(auto i:rest){
    cout<<i.second<<endl;
  }
}