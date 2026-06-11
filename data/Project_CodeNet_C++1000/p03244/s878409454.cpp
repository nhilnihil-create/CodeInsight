#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> v, int n, int index){
  vector<int> rtn;
  map<int, int> temp;
  for(int i = index; i < n; i += 2){
    temp[v[i]]++;
  }
  int maxx = 0;
  int num;
  int sec = 0;
  for(auto a: temp){
    if(a.second > maxx){
      if(sec != 0 && maxx > sec) sec = maxx;
      maxx = a.second;
      num = a.first;
      continue;
    }
    if(a.second > sec && a.second <= maxx){
      sec = a.second;
    }
  }
  rtn.push_back(num);
  rtn.push_back(maxx);
  rtn.push_back(sec);
  return rtn;
}
int main(){
  int n; cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; ++i) cin >> v[i];
  vector<int> ansA = solve(v, n, 0);
  vector<int> ansB = solve(v, n, 1);
  if(ansA[0] != ansB[0]) cout << n - ansA[1] - ansB[1] << endl;
  else cout << min(n - ansA[1] - ansB[2], n - ansA[2] - ansB[1]) << endl; 
}