#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  int x; cin >> x;
  vector<int> v(n);
  for(auto&e:v)cin >> e;
  sort(v.begin(),v.end());
  int cnt = n;
  for(auto e:v) x -= e;
  while(x - v.front() >= 0){
    x -= v.front();
    cnt++;
  }
  cout << cnt << endl;
}
