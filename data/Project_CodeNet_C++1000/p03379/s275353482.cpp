#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  vector<int> v(n);
  vector<pair<int, int>> p(n);
  for(int i = 0; i < n; ++i){
    cin >> p[i].first;
    p[i].second = i;
  }
  sort(p.begin(), p.end());
  int mid = n / 2;
  vector<int> ans(n);
  for(int i = 0; i < n; ++i){
    if(mid <= i) ans[p[i].second] = p[mid - 1].first;
    else ans[p[i].second] = p[mid].first;
  }
  for(int i = 0; i < n; ++i){
    cout << ans[i] << endl;
  }
}